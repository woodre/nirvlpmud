inherit "obj/monster.c";

reset(arg)
{
    set_heart_beat(1);
set_name("hobbit");
set_wc(3);
set_ac(2);
set_level(2);
set_al(200);
set_short("A hairy little creature resembling elves");
set_long("A hairy little creature resembling elves.\n" +
	"He looks like a fat little elve who sits around and blows smoke rings all day.\n");
::reset(0);
}
