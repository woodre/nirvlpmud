/*
* mint.c
* Katya@Nirvana
* Base file given by Jaraxle
* January 2004
*/


#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("Junior Mints");
   add_alias("mints");
   add_alias("mint");
   add_alias("junior");
   add_alias("junior mints");
   add_alias("candy");
   add_alias("box");
   set_short(YEL+"Junior Mints"+NORM);
   set_long("\A small box of junior mints.\n\
Perfect size for someone to "+YEL+"eat"+NORM+".\n");
   set_type("mints");
   set_msg("You eat a junior mint.\n");
   set_msg2(" eats a junior mint.\n");
   set_msg_precharges(YEL+"("+NORM);
   set_msg_postcharges(YEL+")"+NORM);
   add_cmd("eat");
   set_heal(0,50);
   set_charges(4);
   set_stuff(5);
   set_soak(5);
   set_value(650);
   set_msg_stuffed("You are too full to eat anymore candy!\n");
   set_empty_msg("You eat the last junior mint.\n");
}
