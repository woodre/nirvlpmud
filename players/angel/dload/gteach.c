#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("teacher");
  set_short(BLK+BOLD+"Ghost of a teacher"+NORM);
  set_alias("ghost");
  set_long("This former teacher must not have been adept at\n"+
"teaching new adventurers, because his lessons did\n"+
"not serve him very well.\n");
  set_type("ghost");
  set_level(3);
  set_ac(7);
  set_wc(4);
  set_hp(45);
  set_al(0);
  set_aggressive(0);
add_money(100+random(20));
}


