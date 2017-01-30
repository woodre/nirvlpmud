#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("rolling pin");
   set_short("A wooden rolling pin");
   set_alias("pin");
   set_long(
   "A wooden rolling pin with a handle on each end. It is dusty\n"+
   "white with flour and has bits of honeycake dough stuck to it.\n");
   set_weight(1);
   set_value(50);
}


