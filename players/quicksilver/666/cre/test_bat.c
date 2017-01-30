#include "/players/quicksilver/std/std.h"
inherit "players/quicksilver/lib/monster_test.c";

int can_put_and_get(string str) { return 1; }

reset(arg) {
   if(!arg) {
      set_race("bat");
      set_name("a bat");
      set_alias("bat");
      set_short("A small, friendly-looking bat");
      set_long("This bat is very peaceful and passive.\nDon't offset its temper by attacking it.\n");
      set_ac(100000);
      set_hp(100);
      set_level(1);
      set_moveable(0);
      set_action_delay(3);
      set_length_based_delay(1);
	  set_interacting_ob(find_player("quicksilver"));
   }
   ::reset(arg);
   return 1;
}

init() {
	::init();
	if(load_init_script("/players/quicksilver/666/cre/bat_init.mscr")) exec_script("init", 0);
}