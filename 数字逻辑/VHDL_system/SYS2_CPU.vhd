library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity SYS2_CPU is
port(
	  cho:in std_LOGIC_VECTOR(7 downto 0);
	  data:in std_LOGIC_VECTOR(4 downto 0);
	  acc:in unsigned(7 downto 0);
	  acc2:out unsigned(7 downto 0);
	  sysbus:in std_LOGIC_VECTOR(7 downto 0);
	  sysbus2:out std_LOGIC_VECTOR(7 downto 0);
	  reg1:in std_LOGIC_VECTOR(7 downto 0);
	  reg12:out std_LOGIC_VECTOR(7 downto 0);
	  reg2:in std_logic_vector(7 downto 0);
	  mdr:in std_logic_vector(7 downto 0)
	  );
end entity;

architecture one of SYS2_CPU is
begin
	process(cho)
	begin
		IF(cho="00010000") THEN
			acc2<=acc;
			sysbus2<=sysbus;
			reg12<=reg1;
			if data(0)='1'then --load_acc='1',将总线上的内容装载到ACC
			acc2<=unsigned(mdr);
			end if;
			if data(4)='1'then --acc_bus='1',用ACC的内容驱动总线
				sysbus2<=std_logic_vector(acc);
			end if;
			if data(1)='1'then --reg1_bus='1',用reg1的内容驱动总线
				sysbus2<=std_LOGIC_vector(reg1);
			end if;
			if data(2)='1'then --reg2_bus='1',用reg2的内容驱动总线
				sysbus2<=std_logic_vector(reg2);
			end if;
			if data(3)='1'then --load_reg1='1',将总线上的数据装载到reg1
				reg12<=sysbus;
			--	reg_out<=reg1;
			end if;		
		end if;
		--end if;
	end process;

end one;