#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("plum");
   add_alias("gingerbread plum");
   add_alias("gingerbread");
   set_short("A"+MAG+" Gingerbread Plum"+NORM+"");
   set_long(
      "This soft, succulent plum looks as though it will help you feel stronger.\n"+
      "The fruit looks SO good, you might want to 'eat' the 'plum'.\n");
   set_type("bites");
   set_msg("You bite into the plum as juices dribble down your chin.\n");
   set_msg2(" bites into the plum and juices squirt on you.\n");
   add_cmd("bite");
   add_cmd("eat");
   set_heal(10,0);
   set_charges(3);
   set_soak(0);
   set_stuff(5);
   set_value(100);
}

query_save_flag(){
   return 1;
}
