#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

set_id("portal");
set_alias("glowing portal");
set_short("A "+GRN+"vine covered"+NORM+" portal");
set_long("An ancient stone portal, standing here since the grove's creation.\n"+
         "The dark grey stone is typical of the area around Qual'tor\n"+
         "You can "+HIG+"enter"+NORM+" the "+HIG+"portal"+NORM+" and travel to the church.\n");
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
  this_player()->move_player("through the portal#room/church.c");
return 1;
}

get()  { return 0; }
