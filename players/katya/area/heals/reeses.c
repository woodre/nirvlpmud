/*
* reeses.c
* Katya@Nirvana
* Base file given by Jaraxle
* January 2004
*/


#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("Reeses Pieces");
   add_alias("reeses");
   add_alias("pieces");
   add_alias("candy");
   add_alias("bag");
   set_short(YEL+"Reeses pieces"+NORM);
   set_long("\A small bag of reeses pieces.\n\
Perfect size for someone to "+YEL+"eat"+NORM+".\n");
   set_type("reeses");
   set_msg("You pop a reeses in your mouth.\n");
   set_msg2(" pops a reeses in "+this_player()->query_possessive()+" mouth.\n");
   set_msg_precharges(YEL+"("+NORM);
   set_msg_postcharges(YEL+")"+NORM);
   add_cmd("eat");
   set_heal(10,10);
   set_charges(10);
   set_stuff(3);
   set_soak(3);
   set_value(648);
   set_msg_stuffed("You are too full to eat anymore candy!\n");
   set_empty_msg("You eat the last reeses pieces.\n");
}
