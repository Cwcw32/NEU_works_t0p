library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity RAM_CPU is
port(CLK:in std_LOGIC;
	  data:in std_LOGIC_vector(4 downto 0);
	  sys_in:in std_LOGIC_vector(7 downto 0);
	  sys_out:out std_logic_vector(7 downto 0);
	  mdr_out:out std_LOGIC_VECTOR(7 downto 0);
	  mdr_in:in std_logic_vector(7 downto 0);
	  mar_in:in unsigned(2 downto 0);
	  mar_out:out unsigned(2 downto 0);
	  outputt:out std_LOGIC_vector(7 downto 0);
	  sel:in std_LOGIC_vector(2 downto 0)
	  );
end entity;
architecture one of RAM_CPU is
	type mem_array is array( 0 to 7) of std_logic_vector(7 downto 0);
	--用来保存mem，共8个状态
	constant prog:mem_array:=(
		0=>"000"&std_logic_vector(to_unsigned(7,3))&"00",
		--LD+"111"+"00"="00011100"
		1=>"001"&"001"&"01",
		--STA+"001"+"01"="00100101"
		2=>"010"&std_logic_vector(to_unsigned(6,8-3-2))&"00",
		--ADD+"110"+00"="01011000"
		3=>"011"&"001"&"01",
		--SUB+"001"+01"="01100101"
		4=>"11000000",
		--NOP
		5=>"101"&STD_LOGIC_VECTOR(TO_UNSIGNED(6,8-3-2))&"00",
		--JMP1+"110"+00"="10111000"
		6=>std_LOGIC_VECTOR(TO_UNSIGNED(2,8)),
		7=>std_LOGIC_VECTOR(to_unsigned(5,8)),
OTHERS => (OTHERS =>'0'));
signal mar:unsigned(2 downto 0);
signal mdr:std_LOGIC_vector(7 downto 0);
signal sys:std_LOGIC_vector(7 downto 0);
signal mem :mem_array:=prog;
begin
	process(CLK)
	begin
		IF(CLK'EVENT AND CLK='1') THEN
			mar<=mar_in;
			sys<=sys_in;
			mdr<=mdr_in;
			if data(2)='1' then	--load_mar='1',将总线上的内容装载到mar中
				mar<=unsigned(sys(2 downto 0));
			elsif data(4)='1' then	--load_MDR='1',将总线上的内容装载到mdr中
				mdr<=sys;
			elsif data(1)='1' then --CS='1',用MAR的内容设置存储器地址
				if data(0)='1' then --r_nw='1',读取不可写
				--当R_NW无效且CS有效时，MDR的内容放到存储器中
					mdr<=mem(to_integer(mar));
				else 
					mem(to_integer(mar))<=mdr;
				end if;
			end if;
			if data(3)='1' then --mdr_bus='1',用mdr的内容驱动总线
				sys<=mdr;
			end if;
		end if;
		--end if;
	end process;
	mdr_out<=mdr;
	mar_out<=mar;
	sys_out<=sys;
	outputt<=mem(to_integer(unsigned(sel)));
end one;