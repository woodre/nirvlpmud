#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("black squirrel");
  set_short(BLK+BOLD+"A black squirrel"+NORM);
  set_alias("squirrel");
  set_long("The alert black squirrel bobs his head as he\n"+
	   "nibbles on a nut held protectively in his paws.\n"+
	   "His bright eyes glance at you briefly.\n");
  set_type("animal");
  set_level(3);
  set_ac(7);
  set_wc(4);
  set_hp(45);
  set_al(0);
  set_aggressive(0);
  set_dead_ob(this_object());
}

monster_died(ob) {
  object nut;
  nut = clone_object("/players/softly/newbie/obj/nut.c");
  tell_room(environment(),"As the squirrel dies, a nut drops from his paws.\n");
  move_object(nut,environment(ob));
}



