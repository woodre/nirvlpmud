inherit "/obj/generic_heal.c";
#include "/players/softly/misc/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
   set_name("candy cane");
   add_alias("candy");
   add_alias("cane");
   set_short(HIR+"C"+HIW+"a"+HIR+"n"+HIW+"d"+ HIR+"y "+HIW+"C"+HIR+"a"+HIW+"n"+ HIR+"e"+NORM);
   set_long("A red and white striped candy cane.\n");
   set_type("bites");
   set_msg("You take a bite of the sweet candy cane.\n");
   set_msg2(" bites a candy cane.\n");
   add_cmd("suck");
   add_cmd("lick");
   add_cmd("eat");
   set_heal(0,0); 
   set_charges(3);
   set_soak(0);
   set_value(0);
}
short(){ return HIR+"C"+HIW+"a"+HIR+"n"+HIW+"d"+ HIR+"y "+HIW+"C"+HIR+"a"+HIW+"n"+ HIR+"e"+NORM+" ["+charges+"]"; }
