/*
* nacho.c
* Katya@Nirvana
* Base file given by Jaraxle
* January 2004
*/


#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("nacho");
   add_alias("chips");
   add_alias("tortia");
   add_alias("nachos");
   set_short(YEL+"Nachos"+NORM);
   set_long("\An order of tortia chips smothered in melted cheddar.\n\
They look good enough to "+YEL+"munch"+NORM+" on.\n");
   set_type("nacho");
   set_msg("You take a bite of your nachos.\n");
   set_msg2(" takes a bite of "+this_player()->query_possessive()+" nachos.\n");
   set_msg_precharges(YEL+"("+NORM);
   set_msg_postcharges(YEL+")"+NORM);
   add_cmd("munch");
   set_heal(50,50);
   set_charges(3);
   set_stuff(7);
   set_value(902);
   set_msg_stuffed("You can't seem to eat another chip!\n");
   set_empty_msg("You licked the container clean.\n");
}

