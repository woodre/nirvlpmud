/*
* popcorn.c
* Katya@Nirvana
* Base file given by Jaraxle
* January 2004
*/


#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("popcorn");
   add_alias("popcorn");
   add_alias("corn");
   set_short(HIW+"Popcorn"+NORM);
   set_long("\A medium side popcorn with a tad bit of salt.\n\
Perfect size for someone to "+HIW+"eat"+NORM+".\n");
   set_type("popcorn");
   set_msg("You stuff a hand full of popcorn in your mouth.\n");
   set_msg2(" stuffs a hand full of popcorn in "+this_player()->query_possessive()+" mouth.\n");
   set_msg_precharges(HIW+"("+NORM);
   set_msg_postcharges(HIW+")"+NORM);
   add_cmd("eat");
   set_heal(50,50);
   set_charges(3);
   set_stuff(6);
   set_soak(6);
   set_value(902);
   set_msg_stuffed("You are too full to eat anymore popcorn!\n");
   set_empty_msg("You eat the last piece of popcorn.\n");
}

