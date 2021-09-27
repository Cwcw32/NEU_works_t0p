library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

ENTITY RAM_CPU_tb IS 
END RAM_CPU_tb;

ARCHITECTURE A OF RAM_CPU_tb IS
component RAM_CPU is
port(CLK:in std_LOGIC;
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
end component RAM_CPU;
type d_array is array(0 to 7)of std_logic_vector(4 downto 0);
constant x:d_array:=(
	"00010",
	"00011",
	"00100",
	"01000",
	"10010",
	"10011",
	"10100",
	"11000"
);	
signal	data: std_LOGIC_vector(4 downto 0):="00000";
signal   sys_in: std_LOGIC_vector(7 downto 0):="11111111";
signal	sys_out: std_logic_vector(7 downto 0):="00000000";
signal	mdr_out: std_LOGIC_VECTOR(7 downto 0):="00000000";
signal	mdr_in: std_logic_vector(7 downto 0):="11111111";
signal	mar_in: unsigned(2 downto 0):="111";
signal	mar_out: unsigned(2 downto 0):="000";
signal	outputt: std_LOGIC_vector(7 downto 0);
signal	sel: std_LOGIC_vector(2 downto 0):="111";
signal	counttt: unsigned(2 downto 0):="000";
signal	CLKK:  std_logic:='0';
BEGIN
  PROCESS
  BEGIN
    CLKK<=not CLKK ;
	 counttt<=counttt+1;
	--mdr_in<=mdr_in+1;
	--mar_in<=mar_in+1;
	--sys_in<=sys_in+1;
	sel<=sel+1;
	wait for 20 ns;
  END PROCESS;
  PROCESS
  BEGIN
	 data<=x(to_integer(unsigned(counttt)));
  	 wait for 210 ns;
  END PROCESS;
  u1:RAM_CPU port map(CLKK,
	  data,
	  sys_in,
	  sys_out,
	  mdr_out,
	  mdr_in,
	  mar_in,
	  mar_out,
	  outputt,
	  sel
	  );
 END A;
