library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU_CPU is
port (
	data:in std_logic_vector(3 downto 0);
	ir_out: in std_logic_vector(1 downto 0);
	outputt: out unsigned(7 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	acc :in unsigned(7 downto 0);
	reg1_out: in std_logic_vector(7 downto 0);
	reg2_out: in std_logic_vector(7 downto 0);
	cho:in std_LOGIC_VECTOR(7 downto 0)

	);
end entity;
architecture one of ALU_CPU is
signal acc2:unsigned(7 downto 0):=acc;
begin
	process(cho)
	begin
		IF(cho="00100000") THEN
			if ir_out="00" then
				if data(2)='1' then --ALU_ACC='1',用ALU的结果装载到ACC中
					if data(1)='1' then --ALU_add='1',在ALU中执行加操作
						acc2<=acc+unsigned(mdr);
					end if;
				end if;
			elsif ir_out="01" then
				if data(2)='1' then --ALU_ACC='1',用ALU的结果装载到ACC中
					if data(0)='1' then --ALU_sub='1',在ALU中执行减操作
						acc2<=acc-unsigned(reg1_out);
					end if;
				end if;
			elsif ir_out="10"then
				if data(2)='1' then --ALU_ACC='1'，用ALU的结果装载到ACC中
					if data(3)='1' then --ALU_AND='1',在ALU中执行与操作
						acc2<=acc and unsigned(reg2_out);
						end if;
					end if;
				end if;
				outputt<=acc2;

			end if;
	end process;
end one;