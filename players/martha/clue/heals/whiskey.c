#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("bottle");
   add_alias("whiskey");
   set_short("A"+BLU+" Bottle of Whiskey"+NORM+"");
   set_long(
      "A cheap bottle of whiskey.  You might be able to drown your sorrows by taking\n"+
      "a 'swig' of the 'whiskey'.\n");
   set_type("swig");
   set_msg("The whiskey burns going down, making you gasp!\n");
   set_msg2(" takes a swig of whiskey.\n");
   add_cmd("swig");
   add_cmd("drink");
   set_heal(50,50);
   set_charges(3);
   set_intox(2);
   set_soak(0);
   set_stuff(0);
   set_value(1500);
}

query_save_flag(){
   return 1;
}
