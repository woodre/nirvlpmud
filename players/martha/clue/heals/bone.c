#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("bone");
   add_alias("marrow");
   add_alias("treat");
   set_short("A"+YEL+" Dog Bone"+NORM+"");
   set_long(
      "This is a marrow bone that is normally used as a dog treat.  Desperate times\n"+
      "call for desperate measures.  You may be inclined to 'gnaw' on the 'bone'.\n"+
      "and see if it makes you feel any different.\n");
   set_type("bites");
   set_msg("You gnaw on the marrow bone.\n");
   set_msg2(" bites a hunk of the bone off.\n");
   add_cmd("gnaw");
   add_cmd("bite");
   set_heal(0,20);
   set_charges(3);
   set_soak(20);
   set_stuff(20);
   set_value(300);
}

query_save_flag(){
   return 1;
}
