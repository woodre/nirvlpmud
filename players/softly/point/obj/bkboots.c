#include "/players/softly/closed/ansi.h"
inherit "obj/armor.c";

reset(arg){


   set_name("knee boots");
   set_alias("boots");
   set_type("boots");
   set_short(BLK+BOLD+"Black Knee Boots"+NORM);
   set_long("Black knee high boots polished to a high gloss.\n");
   set_ac(2);
   set_weight(1);
   set_value(500);

}

/* Made Saveable - Fred 8/5/03  
query_save_flag() { 
  return 1; 
}
*/
