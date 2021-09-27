library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
 entity COUNTER is
port (
	CLK:in std_logic;
	ch:in unsigned(2 downto 0);
	ch2:out unsigned(2 downto 0);
	cho:out std_logic_vector(7 downto 0)
--	cho2:out std_logic_vector(7 downto 0)
	);
end entity;

architecture one of COUNTER is
begin
	process(CLK)
	begin
		IF(CLK'EVENT AND CLK='1') THEN
			if(ch="000") then
				cho<="00000001";
			elsif(ch="001") then
				cho<="00000010";
			elsif(ch="010")then
				cho<="00000100";
			elsif(ch="011")then
				cho<="00001000";
			elsif(ch="100")then
				cho<="00010000";
			elsif(ch="101")then
				cho<="00100000";
			elsif(ch="110")then
				cho<="01000000";
			elsif(ch="111")then
				cho<="10000000";
			end if;
			ch2<=ch+1;
		end if;
	end process;
end one;