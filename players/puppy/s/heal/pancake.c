#include "/players/puppy/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("pancake");
   set_short("A"+CYN+" Blue Berry Pancake"+NORM+"");
   set_long(
      "A scrumptious looking pancake made with the finest berries\n"+
      "that are found in this land.  You would love to 'eat' it.\n");
   set_type("pancake");
   set_msg("You fold the pancake in half and jam it into your mouth.\n");
   set_msg2(" folds the pancake in half and swallows it whole.\n");
   add_cmd("eat");
   set_heal(20,0);
   set_charges(1);
   set_soak(0);
   set_stuff(15);
   set_value(160);
}

query_save_flag(){
   return 1;
}
