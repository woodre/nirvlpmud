#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("fur");
   set_short("Silver Fox Fur");
   set_long(
   "This is the silver tipped fur of an adult fox.  It will fetch\n"+
   "a nice price at a shop or trading post.\n");
   set_weight(1);
   set_value(400);
}

