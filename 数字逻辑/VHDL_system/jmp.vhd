library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity jmp is
port(	  cho:in std_LOGIC_VECTOR(7 downto 0);

	  acc:in unsigned(7 downto 0);
	  z_flag:out std_LOGIC
	  );
end entity;
architecture one of jmp is
begin
	process(cho)
	begin
		IF(cho="01000000") THEN
			if acc="00000000" then
				z_flag<='1';
			else 
				z_flag<='0';
			end if;
		end if;
		--end if;
	end process;

end one;