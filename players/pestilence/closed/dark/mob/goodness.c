inherit "/obj/monster";
#include "/players/pestilence/ansi.h"
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
 
      set_name(HIW+"Goodness"+NORM);
     set_short(HIW+"Goodness"+NORM);
     set_race( "good");
     set_long("Goody Goody Goodness\n");
     set_level(100);
     set_ac(1000);
     set_wc(1000);
     set_hp(10000);
     set_al(0);
     set_aggressive(0);
   }
}

/*
emit_chan(ob) {
  emit_channel("junk", "\t\t"+HIW+"Light"+NORM+" scorches "+capitalize((string)ob->query_real_name())+" to death!\n");
}
*/
