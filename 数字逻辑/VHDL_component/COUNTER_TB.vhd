library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
ENTITY COUNTER_TB IS

END COUNTER_TB;
ARCHITECTURE A OF COUNTER_TB IS
component COUNTER
port (
	CLK:in std_logic;
	ch:in unsigned(2 downto 0);
	ch2:out unsigned(2 downto 0);
	cho:out std_logic_vector(7 downto 0)
--	cho2:out std_logic_vector(7 downto 0)
	);
end component COUNTER;
signal CLKK:std_LOGIC:='0';
signal ch:unsigned(2 downto 0):="000";
signal ch2:unsigned(2 downto 0):="000";
signal cho:std_LOGIC_vector(7 downto 0):="00000000";
--signal tt0,tt1,tt2,tt3,tt4,tt5,tt6,tt7:std_LOGIC;
BEGIN
   PROCESS
   BEGIN
			CLKK<=not CLKK;
			ch<=ch+1;
			wait for 20 ns;
	END PROCESS;
	u1:COUNTER port map(
	CLKK,ch,ch2,cho
	);
	
END A;
