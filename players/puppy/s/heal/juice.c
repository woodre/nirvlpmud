#include "/players/puppy/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("juice");
   add_alias("smurfjuice");
   add_alias("heal");
   add_alias("smurf juice");
   set_short("A glass of"+HIB+" Smurf Juice"+NORM+"");
   set_long(
      "A glass of blue smurf juice that you might be\n"+
      "able to 'drink.' ");
   set_type("glass");
   set_msg("You take a swig of some smurf juice...YUM!\n");
   set_msg2(" takes a swig of some smurf juice...YUM!\n");
   add_cmd("drink");
   set_heal(10,0);
   set_charges(1);
   set_soak(5);
   set_stuff(0);
   set_value(40);
}

query_save_flag(){
   return 1;
}
