/*
approved by Fakir (as long as there are a max of 5 "freebee's" in the area)
*/

#include "/players/puppy/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("berries");
   add_alias("handful of blue berries");
   add_alias("berry");
   add_alias("blue berries");
   set_short("A handful of"+BLU+" Blue Berries"+NORM+"");
   set_long(
      "A handful of delicious blue berries that you might be able\n"+
      "to 'pop' into your mouth. ");
   set_type("handful");
   set_msg("You gobble down the delicious blue berries.\n");
   set_msg2(" gobbles down the delicious blue berries.\n");
   add_cmd("pop");
   set_heal(5,0);
   set_charges(1);
   set_soak(0);
   set_stuff(10);
   set_value(0);
}

query_save_flag(){
   return 1;
}
