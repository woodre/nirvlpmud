/* Drew Carey's Glasses */

inherit"obj/armor";
#include "/players/aingeal/ansi.h"

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("drew's'glasses");
   set_alias("glasses");
   set_short("Thick, Black-Rimmed Glasses");
   set_long("These are the oversized, thick, squarish black-rimmed glasses\n"+
       "once worn by Drew Carey.  They scream, "+YEL+"'TOTAL NERD'"+NORM+".\n");
set_weight(1);
set_value(500);
set_ac(1);
set_type("helmet");
}
