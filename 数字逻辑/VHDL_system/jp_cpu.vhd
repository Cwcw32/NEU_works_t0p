library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
 entity jp_cpu is
port (
	CLK:in std_logic;
	ch:in unsigned(3 downto 0);
	ch2:out unsigned(3 downto 0);
	cho:out std_logic_vector(7 downto 0)
--	cho2:out std_logic_vector(7 downto 0)
	);
end entity;

architecture one of jp_cpu is
begin
	process(CLK)
	begin
		IF(CLK'EVENT AND CLK='1') THEN
			if(ch="0000") then
				cho<="00000001";
			elsif(ch="0001") then
				cho<="00000010";
			elsif(ch="0010")then
				cho<="00000100";
			elsif(ch="0011")then
				cho<="00001000";
			elsif(ch="0100")then
				cho<="00010000";
			elsif(ch="0101")then
				cho<="00100000";
			elsif(ch="0110")then
				cho<="01000000";
			elsif(ch="0111")then
				cho<="10000000";
			elsif(ch="1000")then
				cho<="00000000";
			end if;
			ch2<=ch+1;
			if ch="1000" then
			ch2<="0000";
			end if;
		end if;
	end process;
end one;