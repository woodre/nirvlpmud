inherit "obj/monster.c";

reset(arg)
{
    set_heart_beat(1);
set_name("elf");
set_wc(3);
set_ac(2);
set_level(2);
set_al(200);
set_short("An Elf Dressed in Blue");
set_long("An Elf Dressed in Blue.\n" +
	"It is Hard at Work picking Fruit.\n");
::reset(0);
}
