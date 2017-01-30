#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    Green grass covers the area.  A well has been dug to provide\n"+
"the area with water.  Some lambs and goats have been tied up\n"+
"next to the well.  An old opened hut seems inviting as it would\n"+
"make good shelter from the direct sunlight.\n";

items = ({
  "hut",
  "It was build from wood and painted white, but the dirt and the\n"+
  "sunlight destroyed most of the paint.  You notice a shadow moving\n"+
  "behind one of it's windows",
  "area",
  "A small grassy area surrounded by an endless desert, like a green\n"+
  "island in the middle of a yellow ocean",
  "well",
  "A deep well has been dug here.  Gray stones surrounds the edges of\n"+
  "the well to prevent anyone from falling in",
  "stones",
  "Gray stones were built two feet high around the edges of the well",
  "shadow",
  "A shadow of a human moving in the hut",
  "plants",
  "Someone has been planting in the middle of the desert. It's mostly\n"+
  "grass, but there are some medical herbs as well as strange looking plants",
  "grassy area",
  "You see different type of plants sarrounding a small wooden hut",
  "lambs",
  "You count seven lambs eating from the grass, while being tied up from\n"+
  "the necks next to the well",
  "goats",
  "You count nine goats eating from the grass, while being tied up from\n"+
  "the necks next to the well",
  "grass",
  "The grass is growing around the hut and the well.",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/r5.c","back",
  "/players/coldwind/desert/rooms/r7.c","enter",
});

}
