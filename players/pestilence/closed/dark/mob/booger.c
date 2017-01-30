inherit "/obj/monster";
#include "/players/pestilence/ansi.h"
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
 
     set_name(HIW+"Wicket's Imagination"+NORM);
     set_short(HIW+"Wicket's Imagination"+NORM);
     set_race( "imagination");
     set_alias("bright light");
     set_long("Bright Light\n");
     set_level(100);
     set_ac(1000);
     set_wc(1000);
     set_hp(10000);
     set_al(0);
     set_aggressive(0);
   }
}


