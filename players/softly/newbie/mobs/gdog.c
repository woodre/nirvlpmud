#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("dog");
  set_short(BLK+BOLD+"Ghost of a dog"+NORM);
  set_alias("ghost");
  set_long("A loyal beast who protected the school and\n"+
	   "the students until the very end...\n");
  set_type("ghost");
  set_level(2);
  set_ac(6);
  set_wc(3);
  set_hp(30);
  set_al(0);
  set_aggressive(0);
}

