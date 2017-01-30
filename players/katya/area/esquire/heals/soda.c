/*
* soda.c
* Katya@Nirvana
* Base file given by Jaraxle
* January 2004
*/


#include "/players/jaraxle/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   
   set_name("soda");
   set_short("A medium soda");
   set_long("A medium soda that looks good enough to drink.\n");
   set_type("soda");
   set_msg("You take a drink of soda.\n");
   set_msg2(" takes a drink of soda.\n");
   set_msg_precharges(HIW+"("+NORM);
   set_msg_postcharges(HIW+")"+NORM);
   add_cmd("drink");
   add_cmd("sip");
   add_cmd("gulp");
   set_heal(50,50);
   set_charges(3);
   set_soak(7);
   set_value(1021);
   set_msg_soaked("You can't seem to make yourself take another drink!\n");
   set_empty_msg("You finish off the last drop of the soda.\n");
}
