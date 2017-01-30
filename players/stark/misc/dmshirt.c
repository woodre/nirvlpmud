#include "/players/stark/defs.h"
inherit "/obj/armor.c";

reset(arg) {
  if(arg) return;
  set_id("dm tshirt");
  set_alias("shirt");
  set_short("T-Shirt that reads: \n"+WHT+"I went to the forbidden forest and all I got was this stupid T-Shirt"+NORM);
  set_long(
"   This is Starks way of saying Good Job.  You braved one of the \n"+
"hardest guilds on Nirvana.  I hope you have fun in your future \n"+
"endeavors.\n");
  set_ac(0);
  set_type("shirt");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(0);
}


drop(){destruct(this_object());}
