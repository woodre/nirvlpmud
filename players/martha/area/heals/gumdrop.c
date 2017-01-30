#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("gumdrop");
   add_alias("gumdrops");
   add_alias("bag");
   add_alias("drop");
   add_alias("gum");
   set_short("A"+HIC+" Bag of Gumdrops"+NORM+"");
   set_long(
      "This small bag of gumdrops looks like it will help you feel stronger.\n"+
      "You might want to 'chew' a 'gumdrop'.\n");
   set_type("gumdrops");
   set_msg("You toss a chewy gumdrop into your mouth.\n");
   set_msg2(" chews loudly on a gumdrop.\n");
   add_cmd("eat");
   add_cmd("chew");
   set_heal(10,0);
   set_charges(3);
   set_soak(0);
   set_stuff(5);
   set_value(100);
}

query_save_flag(){
   return 1;
}
