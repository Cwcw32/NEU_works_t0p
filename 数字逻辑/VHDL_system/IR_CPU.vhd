library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity IR_CPU is
port (
	data:in std_logic_vector(1 downto 0);--data17,data15
--	outputt: out unsigned(4 downto 0);
	mdr :in std_logic_vector(7 downto 0);
	instr_in:in std_logic_vector(7 downto 0);
	instr_out:out std_logic_vector(7 downto 0);
	sys_in :in std_logic_vector(7 downto 0);
	sys_out:out std_logic_vector(7 downto 0);
	op :out std_logic_vector(2 downto 0);
--	count: in unsigned(4 downto 0);
	  cho:in std_LOGIC_VECTOR(7 downto 0)

	);
end entity;

architecture one of IR_CPU is
signal instr:std_logic_vector(7 downto 0):=instr_in;
signal sys:std_logic_vector(7 downto 0):=sys_in;
begin
	process(cho)
	begin
		IF(cho="00001000") THEN
			if data(1)='1' then --load_IR='1',将总线上的内容装载至IR
				instr<=mdr;
			end if;
			if data(0)='1'  then --addR_bus='1',用IR中指令的操作码部分驱动总线
				sys<="00000"&instr(4 downto 2);
			end if;
			--op <= instr_reg(word_w-1 downto word_w-op_w);
		instr_out<=instr;
	sys_out<=sys;
	op<=instr(7 downto 5);
		end if;
	end process;

end one;