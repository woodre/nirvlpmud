#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

set_id("portal");
set_alias("glowing portal");
set_short("A "+WHT+"softly glowing"+NORM+" portal");
set_long("A glowing portal swirling with a soft light, this seems to\n"+
         "be a doorway to another area. Perhaps you could\n"+
         "           "+HIR+"enter"+NORM+" the "+HIR+"portal"+NORM+".\n");
set_weight(1);
set_value(1);
}

init()  {
  ::init();
add_action("enter_portal","enter");
}

enter_portal(str)  {
if(!str) {write("What do you want to enter?\n"); return 1; }
  write("You feel the energy of the glowing portal flow into your body\n"+
        "as you enter the portal.\n");
  this_player()->move_player("through the portal#room/deep_forest1.c");
return 1;
}

get()  { return 0; }
