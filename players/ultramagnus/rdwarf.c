inherit "obj/monster.c";

reset(arg)
{
    set_heart_beat(1);
set_name("dwarf");
set_wc(3);
set_ac(2);
set_level(2);
set_al(200);
set_short("An Dwarf Dressed in Red");
set_long("An Dwarf Dressed in Red.\n" +
	"It is Hard at Work picking Fruit.\n");
::reset(0);
}
