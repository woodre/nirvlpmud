#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("energy bar");
   add_alias("bar");
   set_short("A " + BYEL + HIK + "SOILED DIAPER" + NORM + " flavored energy bar (by OverPowerLord)");
   set_long("This solid bar of recycled food product is surprisingly heavy.\n"+
      "According to the nutritional information on the label, it should be\n"+
      "enough for an entire day's worth of nutrition. Labels don't lie, right?\n");
   set_type("bites");
   set_type_single("bite");
   set_msg(HIY+"You take a bite out of the bar. It's chocolately 'goodness'... overwhelms you.\n"+NORM);
   set_msg2(" takes a bite out of a " + BYEL + HIK + "SOILED DIAPER" + NORM + " flavored energy bar.\n");
   add_cmd("eat");
   set_heal(50,50);
   set_charges(4);
   set_soak(10);
   set_stuff(13);
   set_value(400);
}


query_save_flag()
{
   return 1;
}


