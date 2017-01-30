#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("energy bar");
   add_alias("bar");
   set_short("A hot garbage flavored energy bar (by OverPowerLord)");
   set_long("This is a small but deceptively heavy brick of 'food' which\n"+
      "barely looks edible, as it has the consistency of rotting hay and\n"+
      "seems to be made mostly of sawdust and mucilage...\n");
   set_type("bites");
   set_msg(HIY+"You take a bite out of the food loaf and surprisingly feel... better.\n"+NORM);
   set_msg2(" takes a bite out of a North Korean food loaf.\n");
   add_cmd("eat");
   set_heal(80,20);
   set_charges(4);
   set_soak(1);
   set_stuff(13);
   set_value(400);
}

short()
{
   return "A " + RED + "hot garbage flavored" + NORM + " energy bar (by OverPowerLord) [" + HIR + charges + NORM + "]";
}

query_save_flag()
{
   return 1;
}


