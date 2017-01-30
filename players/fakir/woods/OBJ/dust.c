#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("dust");
   set_short("Fairy Dust");
   set_long(
   "A fine powder of unknown origin and composition. \n");
   set_weight(1);
   set_value(50);
}

