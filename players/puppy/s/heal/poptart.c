#include "/players/puppy/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("poptart");
   add_alias("box");
   add_alias("poptarts");
   set_short("A"+BLU+" Box of Poptarts"+NORM+"");
   set_long(
      "A box containing some homemade poptarts\n"+
      "that you just know would be good to 'eat'.\n");
   set_type("poptarts");
   set_msg("You nibble the edges and then pop the filling into your mouth.\n");
   set_msg2(" nibbles the edges and then swallows the filling.\n");
   add_cmd("eat");
   set_heal(25,0);
   set_charges(6);
   set_soak(0);
   set_stuff(8);
   set_value(600);
}

query_save_flag(){
   return 1;
}
