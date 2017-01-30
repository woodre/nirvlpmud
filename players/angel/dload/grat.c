#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("rat");
  set_short(BLK+BOLD+"Ghost of rat"+NORM);
  set_alias("ghost");
  set_long("The bold grey ghost of a rat stares at you,\n"+
	   "twitching its nose.  Standing on its hind\n"+
	   "legs, he defends his home against invaders.\n");
  set_type("ghost");
  set_level(1);
  set_ac(5);
  set_wc(3);
  set_hp(15);
  set_al(-100);
  set_aggressive(0);
  set_dead_ob(this_object());
}

monster_died(ob) {
  object cheese;
  cheese = clone_object("/players/softly/newbie/obj/cheese.c");
  tell_room(environment(),"A bit of cheese falls from the rat's mouth as he dies.\n");
  move_object(cheese,environment(ob));
}






