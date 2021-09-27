library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

ENTITY PC_CPU_tb IS 
END PC_CPU_tb;

ARCHITECTURE A OF PC_CPU_tb IS
component PC_CPU is
port (
	data:in std_logic_vector(1 downto 0);--data17,data15
	outputt: out unsigned(4 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	count: in unsigned(4 downto 0);
	CLK: in std_logic
	);
end component PC_CPU;
type d_array is array(0 to 1)of std_logic_vector(1 downto 0);
constant x:d_array:=(
	"10",
	"01"
);	
signal data:std_logic_vector(1 downto 0):="00";
signal outputt: unsigned(4 downto 0):="00000";
signal mdr :std_logic_vector(7 downto 0):="00001000";
signal count: unsigned(4 downto 0):="00000";
signal CLKK: std_logic:='0';
signal counttt: std_logic_vector(0 downto 0):="0";
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
  u1:PC_CPU port map (
			data,outputt,mdr,count,CLKK
	);
 END A;
