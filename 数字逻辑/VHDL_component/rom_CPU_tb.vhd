library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

ENTITY ROM_CPU_tb IS 
END ROM_CPU_tb;

ARCHITECTURE A OF rom_CPU_tb IS
component ROM_CPU is
port(CLK:in std_LOGIC;
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
signal CLKK:std_LOGIC:='0';
signal num: unsigned(4 downto 0):="00000";--选择的数字
signal outputt: std_LOGIC_VECTOR(23 downto 0):="000000000000000000000000";
signal temp: std_LOGIC_VECTOR(4 downto 0):="00000";
signal	  temp2: std_LOGIC_VECTOR(2 downto 0):="000";
signal	  temp3: std_LOGIC_VECTOR(1 downto 0):="00";
signal	  temp4: std_LOGIC_VECTOR(3 downto 0):="0000";
signal	  temp5: std_LOGIC_VECTOR(4 downto 0):="00000";
	
BEGIN
  PROCESS
  BEGIN
    CLKK<=not CLKK ;
	 num<=num+1;
	wait for 20 ns;
  END PROCESS;
  u1:ROM_CPU port map (
			CLKK,num,outputt,temp,temp2,temp3,temp4,temp5
	);
 END A;
