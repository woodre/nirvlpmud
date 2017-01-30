/*
* water.c
* Katya@Nirvana
* Base file given by Jaraxle
* January 2004
*/

/* Heal cost s/b as follows:
 * 40 tox / 200 heal = .20 = 16 coins/pt healed
 * 16 coins * 200 pts = 3200 coins
 * 3200 coins * 2/3 for single sps heal = 2133.33 coins
 * rounded to 2135 coins
 * previously sold for 1600
 * Fred [11/14/04]
 */

#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("Spring Water");
   add_alias("spring water");
   add_alias("spring");
   add_alias("water");
   add_alias("bottle");
   set_short(HIW+"Spring Water"+NORM);
   set_long("\A bottle of spring water.\n\
Perfect size for someone to "+HIW+"drink"+NORM+".\n");
   set_type("water");
   set_msg("You take a drink of spring water.\n");
   set_msg2(" takes a drink of spring water.\n");
   set_msg_precharges(HIW+"("+NORM);
   set_msg_postcharges(HIW+")"+NORM);
   add_cmd("drink");
   set_heal(50,0);
   set_charges(4);
   set_stuff(5);
   set_soak(5);
   set_value(685);
   set_msg_stuffed("You are too full to take another drink!\n");
   set_empty_msg("You drink the last drop of the spring water.\n");
}
