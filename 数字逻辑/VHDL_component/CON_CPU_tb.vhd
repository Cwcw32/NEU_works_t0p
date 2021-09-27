library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity CON_CPU_tb is
end entity;

architecture A of CON_CPU_tb is
component CON_CPU
port (
	data:in std_logic_vector(4 downto 0);--尾地址
	--data2:in std_logic_vector(4 downto 0);--尾地址
	add_r:out unsigned(4 downto 0);
	op:in std_logic_vector(2 downto 0);--操作数
	ir_wei:in std_logic_vector(1 downto 0);
	z_flag:in std_logic;
	--mdr :in std_logic_vector(7 downto 0);
	--count: in unsigned(4 downto 0);
	CLK: in std_logic
	);
end component;
	
type d_array is array(0 to 3)of std_logic_vector(4 downto 0);
constant x:d_array:=(
	"11111",
	"11110",
	"11100",
	"00000"
);	
type c_array is array(0 to 3)of std_logic_vector(1 downto 0);
constant y:c_array:=(
	"01",
	"10",
	"01",
	"10"
);
signal data:std_logic_vector(4 downto 0):="00000";
signal add_r: unsigned(4 downto 0):="00000";
signal z_flag:std_logic:='0';
signal ir_wei:std_logic_vector(1 downto 0):="01"; 
signal op:std_logic_vector(2 downto 0):="001";
signal CLKK: std_logic:='0';
signal counttt: std_logic_vector(1 downto 0):="00";
BEGIN
  PROCESS
  BEGIN
    CLKK<=not CLKK ;
	 counttt<=counttt+1;
	wait for 20 ns;
  END PROCESS;
  PROCESS
  BEGIN
	 z_flag<=not z_flag;
	 ir_wei<=y(to_integer(unsigned(counttt)));
	 wait for 10 ns;
  END PROCESS;
  PROCESS
  BEGIN
	 data<=x(to_integer(unsigned(counttt)));
  	 wait for 40 ns;
  END PROCESS;
  u1:CON_CPU port map (
			data,add_r,op,ir_wei,z_flag,CLKK
	);
 END A;
