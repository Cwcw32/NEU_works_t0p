library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

ENTITY ACC_ALU_tb IS 
END ACC_ALU_tb;

ARCHITECTURE A OF ACC_ALU_tb IS
component AlU_CPU is
port (
	data:in std_logic_vector(4 downto 0);
	ir_out: in std_logic_vector(1 downto 0);
	outputt: out unsigned(7 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	acc :in unsigned(7 downto 0);
	reg1_out: in std_logic_vector(7 downto 0);
	reg2_out: in std_logic_vector(7 downto 0);
	CLK: in std_logic
	);
end component ALU_CPU;
type d_array is array(0 to 4)of std_logic_vector(4 downto 0);
constant x:d_array:=(
	"00101",--NOP
	"10100",--ALU_AND
	"01000",--LOAD
	"00110",--ACC
	"00000"--NOPE
);
signal data:std_logic_vector(4 downto 0):="00000";
signal ir_out:std_logic_vector(1 downto 0):="00";
signal outputt: unsigned(7 downto 0):="00000000";
signal mdr :std_logic_vector(7 downto 0):="00000000";
signal acc :unsigned(7 downto 0):="00001000";
signal reg1_out:std_logic_vector(7 downto 0):="00000000";
signal reg2_out:std_logic_vector(7 downto 0):="00001110";
signal CLKK: std_logic:='0';
BEGIN
  PROCESS
  BEGIN
    CLKK<=not CLKK ;
	wait for 20 ns;
  END PROCESS;
  PROCESS
  BEGIN
	 ir_out<=ir_out+1;
	 reg1_out<=reg1_out+1;
	 data<=x(to_integer(unsigned(ir_out)));
  	 wait for 40 ns;
  END PROCESS;
  u1:ALU_CPU port map (
	data=>data,
	ir_out=>ir_out,
	outputt=>outputt,
	mdr=>mdr,
	acc=>acc,
	reg1_out=>reg1_out,
	reg2_out=>reg2_out,
	CLK=>CLKK
	);
 END A;
