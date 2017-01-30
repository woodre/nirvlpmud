#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

   set_id("portal");
   set_alias("dark blue portal");
   set_short("A "+HIB+"dark blue"+NORM+" glowing portal");
   set_long("A glowing portal swirling with a dark blue color, this seems to\n"+
            "be a doorway to another area. Perhaps you could\n"+
       "           "+HIB+"enter"+NORM+" the "+HIB+"portal"+NORM+".\n");
   set_weight(1);
   set_value(1);
}

init()  {
  ::init();
  add_action("enter_portal","enter");
        }

enter_portal(str)  {
  if(str == "portal")  {
  write("You feel the energy of the glowing portal flow into your body\n"+
        "as you enter the portal.\n");
  this_player()->move_player("through the portal#players/mythos/enterance.c");
return 1;
        }
  write("What do you want to enter?\n");
return 1;
        }

get()  { return 0; }

clean_up(){
  return 1; 
}
