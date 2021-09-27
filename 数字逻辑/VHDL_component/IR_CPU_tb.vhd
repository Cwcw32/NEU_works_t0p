library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

ENTITY IR_CPU_tb IS 
END IR_CPU_tb;

ARCHITECTURE A OF IR_CPU_tb IS
component IR_CPU is
port (
	data:in std_logic_vector(1 downto 0);--data17,data15
	mdr :in std_logic_vector(7 downto 0);
	instr_in:in std_logic_vector(7 downto 0);
	instr_out:out std_logic_vector(7 downto 0);
	sys_in :in std_logic_vector(7 downto 0);
	sys_out:out std_logic_vector(7 downto 0);
	op :out std_logic_vector(2 downto 0);
--	count: in unsigned(4 downto 0);
	CLK: in std_logic
	);
end component IR_CPU;
type d_array is array(0 to 3)of std_logic_vector(1 downto 0);
constant x:d_array:=(
	"10",
	"01",
	"00",
	"11"
);	
signal	data:std_logic_vector(1 downto 0):="00";
signal	mdr :std_logic_vector(7 downto 0):="00000000";
signal	instr_in:std_logic_vector(7 downto 0):="00000000";
signal	instr_out:std_logic_vector(7 downto 0):="00000000";
signal	sys_in :std_logic_vector(7 downto 0):="00000000";
signal	sys_out:std_logic_vector(7 downto 0):="00000000";
signal	op :std_logic_vector(2 downto 0):="010";
signal	counttt: unsigned(1 downto 0):="00";
signal	CLKK:  std_logic:='0';
BEGIN
  PROCESS
  BEGIN
    CLKK<=not CLKK ;
	 counttt<=counttt+1;
	wait for 20 ns;
  END PROCESS;
  PROCESS
  BEGIN
	 data<=x(to_integer(unsigned(counttt)));
  	 wait for 210 ns;
  END PROCESS;
  process
  begin
	mdr<=mdr+1;
	wait for 40 ns;
  end process;
  u1:IR_CPU port map (
			data,--data17,data15
	mdr ,
	instr_in,
	instr_out,
	sys_in ,
	sys_out,
	op ,
	CLKK	
	);
 END A;
