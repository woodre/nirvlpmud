#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";


reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  move_object(clone_object("/players/softly/algiers/obj/cleaver.c"),this_object());  

  set_name("lady");
  set_alt_name("church lady");   
  set_alias("chlady1");
  set_long("A powerful grey-haired woman wears a striped apron\n"+
	   "over her sky blue suit.  She stands defiantly before\n"+
	   "a cutting board filled with chickens.\n");
  set_short("A church lady");
  set_race("human");
  set_gender("female");
  set_level(15);
  set_wc(20);
  set_ac(12);
  set_hp(250);
  set_al(0);
  set_aggressive(0);
  add_money(350+random(150));
}
