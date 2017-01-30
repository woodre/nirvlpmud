#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("molasses");
   add_alias("bottle");
   set_short("A"+YEL+" bottle of molasses"+NORM+"");
   set_long(
      "This bottle of molasses looks as though it will help you feel stronger.\n"+
      "You think you could 'chug' 'molasses'.\n");
   set_type("chug");
   set_msg("You chug from the bottle and thick goo coats your stomach!\n");
   set_msg2(" chugs from a bottle of thick, gooey molasses!\n");
   add_cmd("drink");
   add_cmd("chug");
   set_heal(10,0);
   set_charges(3);
   set_soak(0);
   set_stuff(5);
   set_value(100);
}

query_save_flag(){
   return 1;
}
