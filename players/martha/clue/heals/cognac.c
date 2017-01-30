#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("bottle");
   add_alias("cognac");
   set_short("A"+HIY+" Bottle of Cognac"+NORM+"");
   set_long(
      "A bottle of cognac.  You could probably 'sip' some 'cognac' to\n"+
      "calm your nerves.\n");
   set_type("sip");
   set_msg("The cognac burns going down, making you gasp!\n");
   set_msg2(" takes a sip of cognac.\n");
   add_cmd("sip");
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
