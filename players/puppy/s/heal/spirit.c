#include "/players/puppy/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("spirit");
   add_alias("bottle");
   add_alias("spirits");
   set_short(""+HIB+"Spirits"+NORM+"");
   set_long(
      "A bottle of Smurfy Spirits that would wet your taste buds.\n");
   set_type("spirits");
   set_msg("You take a swig of some smurf juice...YUM!\n");
   set_msg2(" takes a swig of some smurf juice...YUM!\n");
   add_cmd("drink");
   set_heal(10,10);
   set_charges(1);
   set_intox(10);
   set_soak(0);
   set_stuff(0);
   set_value(40);
}

query_save_flag(){
   return 1;
}
