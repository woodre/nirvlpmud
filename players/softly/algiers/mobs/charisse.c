#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("charisse");
  set_alt_name("lady");   
  set_alias("woman");
  set_long("\nCharisse is a well constructed young woman with long\n\
brassy blonde hair curving over her shoulders.  She is wearing\n\
a dress that looks very much like a white slip.  She twirls\n\
a lock of hair over her finger while staring blankly at an\n\
imagined speck on the chair.\n");
  set_short("Charisse");
  set_race("human");
  set_gender("female");
  set_level(10);
  set_al(0);
  set_aggressive(0);
  add_money(5+random(25));
}
