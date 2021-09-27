library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
--use work.cpu_def.all;

entity fcpu is
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


architecture rtl of fcpu is

component ROM_CPU is
port(
	  cho:in std_LOGIC_VECTOR(7 downto 0);
	  num:in unsigned(4 downto 0);--选择的数字
	  outputt:out std_LOGIC_VECTOR(23 downto 0);
	  temp:out std_LOGIC_VECTOR(4 downto 0);
	  temp2:out std_LOGIC_VECTOR(2 downto 0);
	  temp3:out std_LOGIC_VECTOR(1 downto 0);
	  temp4:out std_LOGIC_VECTOR(3 downto 0);
	  temp5:out std_LOGIC_VECTOR(4 downto 0);
	  temp6:out std_LOGIC_VECTOR(4 downto 0)
	  
	  );
end component;

component ALU_CPU is
port (
	data:in std_logic_vector(3 downto 0);
	ir_out: in std_logic_vector(1 downto 0);
	outputt: out unsigned(7 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	acc :in unsigned(7 downto 0);
	reg1_out: in std_logic_vector(7 downto 0);
	reg2_out: in std_logic_vector(7 downto 0);
	cho:in std_LOGIC_VECTOR(7 downto 0)

	);
end component;

component IR_CPU is
port (
	data:in std_logic_vector(1 downto 0);--data17,data15
--	outputt: out unsigned(4 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	instr_in:in std_logic_vector(7 downto 0);
	instr_out:out std_logic_vector(7 downto 0);
	sys_in :in std_logic_vector(7 downto 0);
	sys_out:out std_logic_vector(7 downto 0);
	op :out std_logic_vector(2 downto 0);
--	count: in unsigned(4 downto 0);
	  cho:in std_LOGIC_VECTOR(7 downto 0)

	);
end component;

component PC_CPU is
port (
	data:in std_logic_vector(2 downto 0);--data17,data15
	count_out: out unsigned(4 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	count: in unsigned(4 downto 0);
	sys_in:in std_logic_vector(7 downto 0);
	sys_out:out std_logic_vector(7 downto 0);
		  cho:in std_LOGIC_VECTOR(7 downto 0)

	);
end component;

component RAM_CPU is
port(	  cho:in std_LOGIC_VECTOR(7 downto 0);
	  data:in std_LOGIC_vector(4 downto 0);
	  sys_in:in std_LOGIC_vector(7 downto 0);
	  sys_out:out std_logic_vector(7 downto 0);
	  mdr_out:out std_LOGIC_VECTOR(7 downto 0);
	  mdr_in:in std_logic_vector(7 downto 0);
	  mar_in:in unsigned(2 downto 0);
	  mar_out:out unsigned(2 downto 0);
	  outputt:out std_LOGIC_vector(7 downto 0);
	  sel:in std_LOGIC_vector(2 downto 0)
	  );
end component;

component SYS2_CPU is
port(
	  cho:in std_LOGIC_VECTOR(7 downto 0);
	  data:in std_LOGIC_VECTOR(4 downto 0);
	  acc:in unsigned(7 downto 0);
	  acc2:out unsigned(7 downto 0);
	  sysbus:in std_LOGIC_VECTOR(7 downto 0);
	  sysbus2:out std_LOGIC_VECTOR(7 downto 0);
	  reg1:in std_LOGIC_VECTOR(7 downto 0);
	  reg12:out std_LOGIC_VECTOR(7 downto 0);
	  reg2:in std_logic_vector(7 downto 0);
	  mdr:in std_logic_vector(7 downto 0)
	  );
end component;

component jmp is
port(	  cho:in std_LOGIC_VECTOR(7 downto 0);

	  acc:in unsigned(7 downto 0);
	  z_flag:out std_LOGIC
	  );
end component;

component CON_CPU is
port (
	data:in std_logic_vector(4 downto 0);--尾地址
	add_r:out unsigned(4 downto 0);
	op:in std_logic_vector(2 downto 0);--操作数
	ir_wei:in std_logic_vector(1 downto 0);
	z_flag:in std_logic;
	cho:in std_LOGIC_VECTOR(7 downto 0)
	);
end component;

 component jp_cpu is
port (
	CLK:in std_logic;
	ch:in unsigned(3 downto 0);
	ch2:out unsigned(3 downto 0);
	cho:out std_logic_vector(7 downto 0)
--	cho2:out std_logic_vector(7 downto 0)
	);
end component;






	constant word_w:NATURAL:=8;--
	constant op_w:natural:=3;--操作码是三位
	constant rfill:std_logic_vector(op_w-1 downto 0):=(others=>'0');--初始化为0

	signal data_r    : STD_LOGIC_VECTOR(23 DOWNTO 0);--微指令变量
	signal count :unsigned(word_w-op_w-1 downto 0);--计数，PC中使用
	signal count2:unsIGNED(word_w-op_w-1 downto 0);--计数2号
	
	signal op:std_LOGIC_VECTOR(op_w-1 downto 0);--选择的操作码
	signal z_flag: std_LOGIC;--用于JMP1的跳转
	
	signal instr_reg:STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);
	signal instr_reg_2:STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);
	--指令寄存器IR的输出
	
	SIGNAL acc:  UNSIGNED(word_w-1 DOWNTO 0);  --累加器ACC的输出
	SIGNAL acc2:  UNSIGNED(word_w-1 DOWNTO 0);  --累加器ACC的输出
	signal acc3:	UNSIGNED(word_w-1 DOWNTO 0);  --累加器ACC的输出
	
	SIGNAL reg1 :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--寄存器1的输出
	SIGNAL reg12 :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);--寄存器1的输出
	SIGNAL reg2 :  STD_LOGIC_VECTOR(word_w-1 DOWNTO 0):="00001110";--寄存器2的输出
	SIGNAL sysbus_out : STD_LOGIC_VECTOR(word_w-1 DOWNTO 0);
	signal temp      : STD_LOGIC_VECTOR(4 DOWNTO 0);--传给下地址器
	signal temp2		 : std_LOGIC_vector(2 downto 0);--传给PC
	signal temp3		 : std_LOGIC_vector(1 downto 0);--传给ir
	signal temp4		 : std_LOGIC_vector(3 downto 0);--传给alu
	signal temp5		 :std_LOGIC_vector(4 downto 0);--传给mar们
	signal add_r :unsigned(4 downto 0);--微指令的尾地址
	signal addr: integer;
	
	sigNAL sysbus:std_logic_vector(7 downto 0);
	signal sysbus2:std_logic_vector(7 downto 0);
	signal sysbus3:std_logic_vector(7 downto 0);
	signal sysbus4:std_logic_vector(7 downto 0);
	signal sysbus5:std_logic_vector(7 downto 0);
--总线
	signal  wy: std_LOGIC_vector(7 downto 0);
	signal  sel: std_LOGIC_vector(2 downto 0);

	signal mar:unsigned(2 downto 0);
	signal mar2:unsigned(2 downto 0);

	signal mdr:std_LOGIC_vector(7 downto 0);
	signal mdr2:std_LOGIC_vector(7 downto 0);
	signal temp6: std_LOGIC_VECTOR(4 downto 0);
	
	signal cho:std_LOGIC_vector(7 downto 0):="00000000";
	signal cho2:std_LOGIC_vector(7 downto 0):="00000000";
	
	signal ch:unsigned(3 downto 0):="0000";
	signal ch2:unsigned(3 downto 0):="0000";
begin 
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
			outputt<=sysbus;
		when "001"=>
			outputt(word_w-op_w-1 downto 0)<=std_LOGIC_vector(count);
		when "010"=>
			outputt<=STD_LOGIC_vector(acc);
		when "011"=>
			outputt<=instr_reg;
		when "100"=>
			outputt(word_w-op_w-3 downto 0)<=std_logic_vector(mar);
		when "101"=>
			outputt<=mdr;
		when others=>
			outputt<=(others=>'Z');
		end case;
	end process;
	--实时更新数据们们们们们

	process(clock)
	begin
	  ch<=ch2;
	  data_r_out<=data_r;
	  reg_out<=reg1;
	  regg_out<=reg2;
	  op_out<=op;
	  add_r_out<=add_r;
	  mdrout<=mdr;
	  accout<=acc;
	  marout<=mar;
	  irout<=instr_reg;
	  syssout<=sysbus;
	end process;
	process(cho)
	begin
	if cho="00000000"then
		sysbus<=sysbus2;
		sysbus<=sysbus3;
		sysbus<=sysbus4;
		sysbus<=sysbus5;
		acc<=acc2;
		acc<=acc3;
	end if;
	end process;
	--节拍发生器
	u0:jp_cpu port map(clock,ch,ch2,cho);
	--微指令控制器
	u1:ROM_CPU port map(cho,add_r,data_r,temp,temp2,temp3,temp4,temp5,temp6);--直接给temp们赋值给下面使用(100%)
	--下地址发生器
	u2:CON_CPU port map(temp,add_r,op,instr_reg(1 downto 0),z_flag,cho);
	--pc
	u3:PC_CPU port map(temp2,count2,mdr,count,sysbus,sysbus2,cho);
	--ir
	u4:IR_CPU port map(temp3,mdr,instr_reg,instr_reg_2,sysbus2,sysbus3,op,cho);
	--总线设置2,temp6
	u5:SYS2_CPU port map(cho,temp6,acc,acc2,sysbus3,sysbus4,reg1,reg12,reg2,mdr);
	u6:alu_CPU port map(temp4,instr_reg(1 downto 0),acc3,mdr,acc2,reg1,reg2,cho);--记得加上_flag
	--跳转控制器,待制作
	u7:jmp port map(cho,acc,z_flag);
	--mar等
	u8:RAM_CPU port map(cho,temp5,sysbus4,sysbus5,mdr2,mdr,mar,mar2,wy,sel);
	
end rtl;

				
				
			
				