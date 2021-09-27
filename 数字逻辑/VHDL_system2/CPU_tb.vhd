library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity CPU_tb is
end entity;
architecture rtl of CPU_tb is
	component CPU is
port(clock:   	  in std_logic;--时钟脉冲
	  reset:   	  in std_logic;--复位信号
	  mode:	  	  in std_logic_vector(2 downto 0);--操作码
	  mem_addr:	  in unsigned(2 downto 0);--什么地址
	  outputt:    out std_logic_vector(7 downto 0);
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
	  );
	end component CPU;
	-----------------------------wires-----------------------
	signal  clock:   	 std_logic:='0';--时钟脉冲
	signal  reset:   	   std_logic:='0';--复位信号
	signal  mode:	  	   std_logic_vector(2 downto 0):="010";--操作码
	signal  mem_addr:	   unsigned(8 -3-3 downto 0):="000";
	signal  outputt:  	   std_logic_vector(8-1 downto 0):="00000000";
	signal  data_r_out :   STD_LOGIC_VECTOR(23 DOWNTO 0):="000000000000000000000000";--微指令的输出
	signal  reg_out: 	   std_logic_vector(8-1 downto 0):="00000000";--寄存器1的结果
	signal  regg_out:	   std_logic_vector(8-1 downto 0):="00000000";--寄存器2的结果
	signal  op_out:	   std_logic_vector(3-1 downto 0):="000";--操作码的结果
	signal  add_r_out:  unsigned(4 downto 0):="00000";
	signal  mdrout  :  STD_LOGIC_VECTOR(8-1 DOWNTO 0):="00000000";
	signal  accout:   UNSIGNED(8-1 DOWNTO 0):="00000000";
	signal  marout  :  UNSIGNED(8-3-3 DOWNTO 0):="000";--存储器MAR的输出
	signal  irout   :  STD_LOGIC_VECTOR(8-1 DOWNTO 0):="00000000";
	signal  syssout : STD_LOGIC_VECTOR(8-1 DOWNTO 0):="00000000";
	-----------------
begin 
	process
	begin
		clock<=not clock ;
		mem_addr<=mem_addr+1;
	wait for 20ns;
	end process;
	reset <='1';
	u0: CPU port map(clock=>clock,
						reset=>reset,
						mode=>mode,
						mem_addr=>mem_addr,
						outputt=>outputt,
						data_r_out=>data_r_out,
						reg_out=>reg_out,
						regg_out=>regg_out,
						op_out=>op_out,
						add_r_out=>add_r_out,
						mdrout=>mdrout,
						accout=>accout,
						marout=>marout,
						irout=>irout,
						syssout=>syssout);
end architecture;

				
				
			
				