#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("glass");
   add_alias("cognac");
   set_short("A"+HIG+" Glass of Cognac"+NORM+"");
   set_long(
      "A glass of cognac.  You could probably 'sip' some 'cognac' to\n"+
      "calm your nerves.\n");
   set_type("sip");
   set_msg("The cognac burns going down, making you gasp!\n");
   set_msg2(" takes a sip of cognac.\n");
   add_cmd("sip");
   add_cmd("drink");
   set_heal(25,0);
   set_charges(3);
   set_intox(25);
   set_soak(0);
   set_stuff(0);
   set_value(1000);
}

query_save_flag(){
   return 1;
}
