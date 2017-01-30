#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("student");
  set_short(BLK+BOLD+"Ghost of a Student"+NORM);
  set_alias("ghost");
  set_long("This student must have been trapped inside the\n"+
	   "school when he died.  He is still carrying his\n"+
	   "explorer's notes.\n");
  set_type("ghost");
  set_level(2);
  set_ac(6);
  set_wc(3);
  set_hp(30);
  set_al(0);
  set_aggressive(0);
  add_money(60+random(30));
}

