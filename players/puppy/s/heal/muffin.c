#include "/players/puppy/define.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("muffin");
   add_alias("blue berry muffin");
   set_short("A"+CYN+" Blue Berry Muffin"+NORM+"");
   set_long(
      "A small blue berry muffin that you might want to 'eat'.\n");
   set_type("muffin");
   set_msg("You swallow the muffin whole.\n");
   set_msg2(" swallows the muffin whole.\n");
   add_cmd("eat");
   set_heal(10,0);
   set_charges(1);
   set_soak(0);
   set_stuff(5);
   set_value(40);
}

query_save_flag(){
   return 1;
}
