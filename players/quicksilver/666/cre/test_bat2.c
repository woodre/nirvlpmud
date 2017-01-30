#include "/players/quicksilver/std/std.h"
inherit "players/quicksilver/lib/mob_script.c";

reset(arg) {
   if(!arg) {
      set_race("bat");
      set_name("a bat");
      set_alias("bat");
      set_short("A small, friendly-looking bat");
      set_long("This bat is very peaceful and passive.\nDon't offset it's temper by attacking it.\n");
      set_ac(100000);
      set_hp(100);
      set_level(1);
      set_moveable(0);
      set_action_delay(3);
      set_length_based_delay(1);
   }
   ::reset(arg);
   return 1;
}

init() {
	::init();
	if(load_script("/players/quicksilver/666/cre/bat.mscr")) exec_script();
}
