#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("pack");
   add_alias("cigarette");
   add_alias("cig");
   set_short("A"+HIC+" Pack of Cigarettes"+NORM+"");
   set_long(
      "Cigarettes are bad for your health!  Except this pack seems to be made of\n"+
      "something other than nicotine and tar.  Maybe you could 'smoke' a 'cig'arette\n"+
      "and see if it makes you feel any different.\n");
   set_type("puffs");
   set_msg("You take a long, slow drag from a cigarette.\n");
   set_msg2(" takes a long, slow drag from a cigarette.\n");
   add_cmd("smoke");
   add_cmd("puff");
   set_heal(50,50);
   set_charges(3);
   set_soak(7);
   set_stuff(7);
   set_value(1500);
}

query_save_flag(){
   return 1;
}
