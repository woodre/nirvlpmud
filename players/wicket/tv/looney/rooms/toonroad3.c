inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("dizzy", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/dizzy.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A "+HIK+"Road "+NORM+"in "+HIC+"Tiny"+HIW+" Toon"+HIC+" Town"+NORM;
  long_desc = " A small road in tiny toon town. Off to the west is a small house\n\
  with a white little wooden fence around it. Soft green grass surrounds the\n\
  house and a cute little mailbox is next to the fence. To the east is a little\n\
  green house next to the pond that is in the south direction the house. Reeds\n\
  and stuff grow along the house next to the pond. To the south the road goes\n\
  back to the entrance, to the north is more road.\n";
  items = 
  ({
    "mailbox",
    "A cute little mailbox that says Hamton Pig",
    "fence",
    "A little wooden fence that surrounds the house to the west",
    "pond",
    "A soft crystal clear blue pond",
    "reeds",
    "Reeds are growing around the pond of all heights",
    "house",
    "A small green house is off to the east and another small house is off to the west",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/toonroad2.c","south",
  "/players/wicket/tv/looney/rooms/hamtonhouse.c","west",
  "/players/wicket/tv/looney/rooms/pluckyhouse.c","east",
  "/players/wicket/tv/looney/rooms/toonroad4.c","north",
  });
  } 