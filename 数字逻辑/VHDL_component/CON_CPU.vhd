library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity CON_CPU is
port (
	data:in std_logic_vector(4 downto 0);--尾地址
	add_r:out unsigned(4 downto 0);
	op:in std_logic_vector(2 downto 0);--操作数
	ir_wei:in std_logic_vector(1 downto 0);
	z_flag:in std_logic;
	CLK: in std_logic
	);
end entity;

architecture one of CON_CPU is
begin
	process(CLK)
	variable temp:std_logic_vector(4 downto 0);
	begin
		IF(CLK'EVENT AND CLK='1') THEN
			if data="11111" then--按照指令表，"11111"代表LOAD_MAR,ADDR_BUS
				temp:="01"&op;
				add_r<=unsigned(temp);
			elsif data="11110" then--acc_bus,用acc的内容驱动总线
				if ir_wei="10" then
					add_r<="00110";
				elsif ir_wei="01" then
					add_r<="00101";
				end if;
			elsif data="11100" then
				if z_flag='0'then
					add_r<="10011";--当R_NW无效且CS有效时，MDR的内容放到存储器中code(19)
				else
					add_r<="10100";
					--code(20)
				end if;
			else
				add_r <=unsigned(data);
			end if;
		end if;
	end process;
end one;