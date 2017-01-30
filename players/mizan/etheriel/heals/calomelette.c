#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("calcutta omelette");
   add_alias("omelette");
   add_alias("omelet");
   set_short("A Calcutta Omelette");
   set_long("This is a disgusting looking... aw hell, it's a freaking\n"+
      "pile of poop all mixed up with egg, Indian food, and tandoori sauce.\n"+
      "It can't possibly be good for you if eaten...\n");
   set_type("bites");
   set_msg(HIY+"You take a bite out of the omelette... and feel HORRIBLE.\n"+NORM);
   set_msg2(" takes a bite out of something that tastes like... POOP.\n");
   add_cmd("eat");
   set_heal(-80,-20);
   set_charges(4);
   set_soak(1);
   set_stuff(13);
   set_value(400);
}

short()
{
   return "A " + RED + "Calcutta Omelette" + NORM + " [" + HIR + charges + NORM + "]";
}

query_save_flag()
{
   return 1;
}


