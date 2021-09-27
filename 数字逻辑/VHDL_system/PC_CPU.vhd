library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC_CPU is
port (
	data:in std_logic_vector(2 downto 0);--data17,data15
	count_out: out unsigned(4 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	count: in unsigned(4 downto 0);
	sys_in:in std_logic_vector(7 downto 0);
	sys_out:out std_logic_vector(7 downto 0);
		  cho:in std_LOGIC_VECTOR(7 downto 0)

	);
end entity;

architecture one of PC_CPU is
signal count2:unsigned(4 downto 0):=count;
signal sys:std_logic_vector(7 downto 0):=sys_in;
begin
	process(cho)
	begin
		IF(cho="00000100") THEN
			if data(2)='1' then --PC_bus='1'，用pc的内容驱动总线
				sys<="000"&STD_LOGIC_VECTOR(count2);
			end if;
			if data(1)='1' then --load_PC='1'，将总线上的内容装载到PC
				count2<=unsigned(mdr(4 downto 0));
			elsif data(0)='1' then --inc_pc='1'，PC加1并存储到PC中
				count2 <=count2 +1;
			else
				count2<=count2;
			end if;
			sys_out<=sys;
			count_out<=count2;
		end if;
	end process;
	
end one;