#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("fur");
   set_short("Bobcat Fur");
   set_long(
   "This is the spotted fur of a baby bobcat.  It will fetch\n"+
   "a nice price at a shop or trading post.\n");
   set_weight(1);
   set_value(100);
}

