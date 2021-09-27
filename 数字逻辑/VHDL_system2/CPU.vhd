library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
--use work.cpu_def.all;

entity CPU is
port(clock:   	  in std_logic;--时钟脉冲
	  reset:   	  in std_logic;--复位信号
	  mode:	  	  in std_logic_vector(2 downto 0);--操作码
	  mem_addr:	  in unsigned(2 downto 0);--存储的地方
	  outputt:  	  out std_logic_vector(7 downto 0);
	  data_r_out : OUT  STD_LOGIC_VECTOR(23 DOWNTO 0);--微指令的输出
	  reg_out: 	  out std_logic_vector(7 downto 0);--寄存器1的结果
	  regg_out:	  out std_logic_vector(7 downto 0);--寄存器2的结果
	  op_out:	  out std_logic_vector(2 downto 0);--操作码的结果
	  add_r_out:  out unsigned(4 downto 0);
	  mdrout  :  out STD_LOGIC_VECTOR(7 DOWNTO 0);
	  accout:  out UNSIGNED(7 DOWNTO 0);
	  marout  :out  UNSIGNED(2 DOWNTO 0);--存储器MAR的输出
	  irout   :out  STD_LOGIC_VECTOR(7 DOWNTO 0);
	  syssout :out STD_LOGIC_VECTOR(7 DOWNTO 0)
	  )
	  ;
end entity;


architecture rtl of CPU is
	type opcode is (LD,STA,ADD,SUB,AND1,JMP1,HALT);--操作，取指令，存指令，加减与，跳转，停机
	-------------------
	--LD 000
	--STA 001
	--ADD 010
	--SUB 011
	--AND 100
	--JMP 101
	--NOP 110
	------------------
	constant word_w:NATURAL:=8;--
	constant op_w:natural:=3;--操作码是三位
	constant rfill:std_logic_vector(op_w-1 downto 0):=(others=>'0');--初始化为0
	type mem_array is array( 0 to 2**(word_w-op_w-2)-1) of std_logic_vector(word_w-1 downto 0);
	--用来保存mem，共8个状态
	signal mem :mem_array;
	constant prog:mem_array:=(
		0=>"000"&std_logic_vector(to_unsigned(7,word_w-op_w-2))&"00",
		--LD+"111"+"00"="00011100"
		1=>"001"&"001"&"01",
		--STA+"001"+"01"="00100101"
		2=>"010"&std_logic_vector(to_unsigned(6,word_w-op_w-2))&"00",
		--ADD+"110"+00"="01011000"
		3=>"011"&"001"&"01",
		--SUB+"001"+01"="01100101"
		4=>"11000000",
		--NOP
		5=>"101"&STD_LOGIC_VECTOR(TO_UNSIGNED(6,word_w-op_w-2))&"00",
		--JMP1+"110"+00"="10111000"
		6=>std_LOGIC_VECTOR(TO_UNSIGNED(2,word_w)),
		7=>std_LOGIC_VECTOR(to_unsigned(5,word_w)),
OTHERS => (OTHERS =>'0'));
	TYPE MICROCODE_ARRAY IS ARRAY(0 TO 20) OF STD_LOGIC_VECTOR(23 DOWNTO 0);
	--微指令
	CONSTANT code      : microcode_array:=(
				0=>  "000000001001010000000001",
				1=>  "000000000000000110000010",
				2=>  "000000000110000000000011",
				3=>  "000000000001001000011111",
				4=>  "000000010010000000000000",
				5=>  "000100000000000000000000",
				6=>  "100000000000000000000111",
				7=>  "000010000001000000001111",
				8=>  "000000000000000110000100",
				9=>  "010000000000000000011110",
			   10=> "000000000000000110010000",
			   11=> "000001000000100000100000",
			   12=> "000010000001000000010001",
       		13=> "000000000000000110011100",
		      14=> "000000000000000000000000",
		      15=> "000000000000000100000000",
			   16=> "000000000010100001000000",
			   17=> "000000000000000110010010",
		      18=> "001000000010100000000000",
		      19=> "000000100010000000000000",
		      20=> "000000000000000000000000");
	signal count :unsigned(word_w-op_w-1 downto 0);--计数，PC中使用
	signal op:std_LOGIC_VECTOR(op_w-1 downto 0);--选择的操作码
	signal z_flag: std_LOGIC;--用于JMP1的跳转
	SIGNAL mdr_out  :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--数据寄存器MDR的输出
	SIGNAL mar_out  :  UNSIGNED(word_w-op_w-3 DOWNTO 0);--存储器MAR的输出
	SIGNAL ir_out   :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--指令寄存器IR的输出
	SIGNAL acc_out  :  UNSIGNED(word_w-1 DOWNTO 0);  --累加器ACC的输出
	SIGNAL reg1_out  :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--寄存器1的输出
	SIGNAL reg2_out  :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--寄存器2的输出
	SIGNAL sysbus_out : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);
begin 
	process(reset,clock)--总线管理大师
		VARIABLE instr_reg : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--IR
		VARIABLE acc       : UNSIGNED(word_w-1 DOWNTO 0);--累加器
		CONSTANT zero      : UNSIGNED(word_w-1 DOWNTO 0):=(OTHERS =>'0');
		VARIABLE mdr       : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--数据寄存器
		VARIABLE reg1      : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--寄存器1
      VARIABLE reg2      : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--寄存器2
		VARIABLE mar       : UNSIGNED(word_w-op_w-3 DOWNTO 0);
		VARIABLE sysbus    : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);			
		VARIABLE microcode : microcode_array;
		VARIABLE add_r     : UNSIGNED(4 DOWNTO 0);--下地址
    	VARIABLE data_r    : STD_LOGIC_VECTOR(23 DOWNTO 0);--微指令变量
		VARIABLE temp      : STD_LOGIC_VECTOR(4 DOWNTO 0);--中间变量一枚
	begin
		reg2:="00000111";--给寄存器2赋初值
		if reset='0'THEN--复位端为0，执行初始化功能
			add_r:=(others=>'0');
			count<=(others=>'0');
			instr_reg:=(others=>'0');
			acc:=(others=>'0');
			mdr:=(others=>'0');
			reg1 :=(others=>'0');
			reg2:=(others=>'0');
			mar:=(others=>'0');
			z_flag<='0';
			mem<=prog;
			sysbus :=(others=>'0');
		elsif rising_edge(clock) then--上升沿
			--微指令控制器
			data_r:=code(to_integer(add_r));
			if data_r(4 downto 0)="11111" then--按照指令表，"11111"代表LOAD_MAR,ADDR_BUS
				temp:="01"&op(2 downto 0);
				add_r:=unsigned(temp);
			elsif data_r(4 downto 0)="11110" then--acc_bus,用acc的内容驱动总线
				if ir_out(1 downto 0)="10" then
					add_r:="00110";
				elsif ir_out(1 downto 0)="01" then
					add_r:="00101";
				end if;
			elsif data_r(4 downto 0)="11100" then
				if z_flag='0'then
					add_r:="10011";--当R_NW无效且CS有效时，MDR的内容放到存储器中code(19)
				else
					add_r:="10100";
					--code(20)
				end if;
			else
				add_r :=unsigned(data_r(4 downto 0));
			end if;
			data_r_out <=data_r;
			add_r_out <=add_r;
			
			--PC
			if data_r(15)='1' then --PC_bus='1'，用pc的内容驱动总线
				sysbus:=rfill&STD_LOGIC_VECTOR(count);
			end if;
			if data_r(17)='1' then --load_PC='1'，将总线上的内容装载到PC
				count<=unsigned(mdr(word_w-op_w-1 downto 0));
			elsif data_r(10)='1' then --inc_pc='1'，PC加1并存储到PC中
				count <=count +1;
			else
				count<=count;
			end if;
			
			--IR
			if data_r(14)='1' then --load_IR='1',将总线上的内容装载至IR
				instr_reg:=mdr;
			end if;
			if data_r(9)='1'  then --addR_bus='1',用IR中指令的操作码部分驱动总线
				sysbus:="00"&rfill&instr_reg(word_w-op_w-1 downto 2);
			end if;
			op <= instr_reg(word_w-1 downto word_w-op_w);
			ir_out<=instr_reg;
			op_out<=op;
			irout<=ir_out;
			--*************************
			--**********ALU************
			--*************************
			
			--总线的设置
			
			if data_r(16)='1'then --load_acc='1',将总线上的内容装载到ACC
				acc:=unsigned(mdr);
			end if;
			if data_r(22)='1'then --acc_bus='1',用ACC的内容驱动总线
				sysbus:=std_logic_vector(acc);
			end if;
			if data_r(18)='1'then --reg1_bus='1',用reg1的内容驱动总线
				sysbus:=std_LOGIC_vector(reg1);
			end if;
			if data_r(19)='1'then --reg2_bus='1',用reg2的内容驱动总线
				sysbus:=std_logic_vector(reg2);
			end if;
			if data_r(20)='1'then --load_reg1='1',将总线上的数据装载到reg1
				reg1:=sysbus;
				reg_out<=reg1;
			end if;
			--根据ir寄存器执行ALU的操作
			if ir_out(1 downto 0)="00" then
				if data_r(11)='1' then --ALU_ACC='1',用ALU的结果装载到ACC中
					if data_r(6)='1' then --ALU_add='1',在ALU中执行加操作
						acc:=acc+unsigned(mdr);
					end if;
				end if;
			elsif ir_out(1 downto 0)="01" then
				if data_r(11)='1' then --ALU_ACC='1',用ALU的结果装载到ACC中
					if data_r(5)='1' then --ALU_sub='1',在ALU中执行减操作
						acc:=acc-unsigned(reg1_out);
					end if;
				end if;
		--	elsif ir_out(1 downto 0)="10"then

			end if;
			if data_r(11)='1' then --ALU_ACC='1'，用ALU的结果装载到ACC中
				if data_r(21)='1' then --ALU_AND='1',在ALU中执行与操作
				acc:=acc and unsigned(reg2_out);
				end if;
			end if;
			--根据结果对跳转的指令寄存器置位
			if acc=zero then
				z_flag<='1';
			else 
				z_flag<='0';
			end if;
			acc_out<=acc;
			accout<=acc_out;
			
			
			--*************************
			--**********mar等************
			--*************************
			
			if data_r(12)='1' then	--load_mar='1',将总线上的内容装载到mar中
				mar:=unsigned(sysbus(word_w-op_w-3 downto 0));
			elsif data_r(23)='1' then	--load_MDR='1',将总线上的内容装载到mdr中
				mdr:=sysbus;
			elsif data_r(8)='1' then --CS='1',用MAR的内容设置存储器地址
				if data_r(7)='1' then --r_nw='1',读取不可写
				--当R_NW无效且CS有效时，MDR的内容放到存储器中
					mdr:=mem(to_integer(mar));
				else 
					mem(to_integer(mar))<=mdr;
				end if;
			end if;
			if data_r(13)='1' then --mdr_bus='1',用mdr的内容驱动总线
				sysbus:=mdr;
			end if;
			mdr_out<=mdr;
			mar_out<=mar;
			mdrout<=mdr_out;
			marout<=mar_out;
		end if;
			sysbus_out<=sysbus;
			syssout<=sysbus_out;
			reg1_out<=reg1;
			reg2_out<=reg2;
			regg_out<=reg2_out;
	end process;
	
	process(mode,mem_addr)
	begin
		--模式选择
		--mode=0->sysbus
		--mode=1->PC
		--mode=2->result of ALU
		--mode=3->IR
		--mode=4->MAR
		--mode=5->MDR
		--mode=6->mem
		outputt<=(others=>'0');
		CASE mode is
		when "000"=>
			outputt<=sysbus_out;
		when "001"=>
			outputt(word_w-op_w-1 downto 0)<=std_LOGIC_vector(count);
		when "010"=>
			outputt<=STD_LOGIC_vector(acc_out);
		when "011"=>
			outputt<=ir_out;
		when "100"=>
			outputt(word_w-op_w-3 downto 0)<=std_logic_vector(mar_out);
		when "101"=>
			outputt<=mdr_out;
		when "110"=>
			outputt<=mem(TO_integer(mem_addr));
		when others=>
			outputt<=(others=>'Z');
		end case;
	end process;
end architecture;

				
				
			
				