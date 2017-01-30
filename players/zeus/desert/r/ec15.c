inherit "room/room";       /* ec15 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  This part of the desert seems much rockier than other parts.  The\n"+
"ground is very dry and cracked, and is highlighted by many small\n"+
"craters, as well as sand and loose rocks.  The wind is whipping\n"+
"across the desert, carrying dust and sand through the air.  The sky\n"+
"is a mass of swirling darkness.\n";
  items=({
  "desert",
"The desert is fairly rocky and uneven here, littered with small rocks\n"+
"and craters in the ground",
  "ground",
"The ground is fairly uneven here, scattered with small rocks and\n"+
"craters.  A thin coating of sand rests upon it delicately",
  "sand",
"The grains of sand blow through the air, obscuring your vision. On\n"+
"the ground a thin layer of sand coats the rocks and craters",
  "craters",
"Most of the craters are just a few inches deep.  Some of them have\n"+
"smooth edges while others are broken and rough.  Small rocks are\n"+
"littered in and around them",
  "rocks",
"Small rocks are scattered over the ground.  Many of the deeper\n"+
"craters have a small pile of rocks near the center.  They are all\n"+
"the same color as the ground and entirely dry",
  "sky",
"The sky seems to mix with itself as the wind blows through it.  It\n"+
"almost appears liquid as your stare into it",
  "wind",
"Wind is whipping over the flat rocky ground",
  "cracks",
"Many small cracks can be seen in the dry ground",
  });
  dest_dir=({  "/players/zeus/desert/r/ec10.c", "north",
               "/players/zeus/desert/r/ec16.c", "east",  });
  }
 }

void init(){
  ::init();
  add_action("south_dir", "south");
  add_action("search_cmd", "search");
}

south_dir(){
  write("You walk south into the darkness...\n\n");
  this_player()->move_player("south#/players/zeus/desert/r/ec19.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

