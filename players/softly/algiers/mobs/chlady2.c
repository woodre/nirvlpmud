#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";


reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  move_object(clone_object("/players/softly/algiers/obj/cknife.c"),this_object());  

  set_name("lady");
  set_alt_name("church lady");   
  set_alias("chlady2");
  set_long("Over her red knit dress the woman wears a large white\n"+
	   "apron.  Her flour-covered large hands are strong after\n"+
	   "years of preparing food for crowds of churchgoers.\n");
  set_short("A church lady");
  set_race("human");
  set_gender("female");
  set_level(15);
  set_wc(20);
  set_ac(12);
  set_hp(250);
  set_al(0);
  set_aggressive(0);
  add_money(450+random(50));
  set_chat_chance(5);
  load_chat("The church lady warns: You have no business here.\n");
  load_chat("The church lady says: Let me get my work done before the service is over.\n");
  load_chat("The church lady complains: Nothing is as it used to be.\n");
}
