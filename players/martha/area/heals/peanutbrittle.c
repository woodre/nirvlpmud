#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("peanut brittle");
   add_alias("peanut");
   add_alias("brittle");
   set_short("A"+YEL+" chunk of Peanut Brittle"+NORM+"");
   set_long(
      "This chunk of peanut brittle looks as though it will help you feel stronger.\n"+
      "You think you could 'bite' the peanut 'brittle'.\n");
   set_type("bites");
   set_msg("You bite into the peanut brittle and chip a tooth!\n");
   set_msg2(" bites into the peanut brittle and chips a tooth!\n");
   add_cmd("eat");
   add_cmd("bite");
   set_heal(10,0);
   set_charges(3);
   set_soak(0);
   set_stuff(5);
   set_value(100);
}

query_save_flag(){
   return 1;
}
