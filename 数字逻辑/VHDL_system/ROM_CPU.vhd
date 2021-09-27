library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity ROM_CPU is
port(
	  cho:in std_LOGIC_VECTOR(7 downto 0);
	  num:in unsigned(4 downto 0);--选择的数字
	  outputt:out std_LOGIC_VECTOR(23 downto 0);
	  temp:out std_LOGIC_VECTOR(4 downto 0);
	  temp2:out std_LOGIC_VECTOR(2 downto 0);
	  temp3:out std_LOGIC_VECTOR(1 downto 0);
	  temp4:out std_LOGIC_VECTOR(3 downto 0);
	  temp5:out std_LOGIC_VECTOR(4 downto 0);
	  temp6:out std_LOGIC_VECTOR(4 downto 0)
	  
	  );
end entity;
architecture one of ROM_CPU is
	TYPE MICROCODE_ARRAY IS ARRAY(0 TO 20) OF STD_LOGIC_VECTOR(23 DOWNTO 0);
	--微指令
	CONSTANT code      : microcode_array:=(
				0=>  "000000001001010000000001",
				1=>  "000000000000000110000010",
				2=>  "000000000110000000000011",
				3=>  "000000000001001000011111",
				4=>  "000000010010000000000000",
				5=>  "000100000000000000000000",
				6=>  "100000000000000000000111",
				7=>  "000010000001000000001111",
				8=>  "000000000000000110000100",
				9=>  "010000000000000000011110",
			   10=> "000000000000000110010000",
			   11=> "000001000000100000100000",
			   12=> "000010000001000000010001",
       		13=> "000000000000000110011100",
		      14=> "000000000000000000000000",
		      15=> "000000000000000100000000",
			   16=> "000000000010100001000000",
			   17=> "000000000000000110010010",
		      18=> "001000000010100000000000",
		      19=> "000000100010000000000000",
		      20=> "000000000000000000000000");
signal output1:std_LOGIC_VECTOR(23 downto 0):="000000000000000000000000";
signal sel:unsigned(4 dowNto 0):=num;
begin
	sel<=num;
	process(cho)
	begin
		IF(cho="00000001") THEN
		output1<=code(to_integer(sel));
		outputt<=output1;
		temp<=output1(4 downto 0);
		temp2<=output1(17)&output1(15)&output1(10);
		temp3<=output1(14)&output1(9);
		temp4<=output1(21)&output1(11)&output1(6)&output1(5);
		temp5<=output1(23)&output1(13)&output1(12)&output1(8)&output1(7);
		temp6<=output1(22)&output1(20)&output1(19)&output1(18)&output1(16);
		end if;
		--end if;
	end process;

end one;