#include "/obj/ansi.h"

inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("maddog");
   add_alias("wine");
   add_alias("mad");
   set_short("a bottle of "+HIM+"Maddog"+NORM);
   set_long("This is a bottle of grape Maddog wine. It is\n"+
      "quite possibly the cheapest wine on earth\n");
   set_type("drinks");
   set_msg("You take a drink of "+HIM+"Maddog\n"+NORM);
   set_msg2(" takes a drink of "+HIM+"Maddog "+NORM+"and nearly pukes.\n");
   add_cmd("drink");
   add_cmd("swig");
   add_cmd("sip");
   set_heal(50,50);
   set_charges(3);
   set_intox(10);
   set_value(800);
}
