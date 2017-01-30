#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("quiver");
   set_short("A leather quiver");
   set_long(
   "A leather quiver with a few steel tipped arrows inside. \n");
   set_weight(1);
   set_value(100);
}

