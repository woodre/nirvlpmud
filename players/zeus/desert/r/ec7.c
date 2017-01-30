inherit "room/room";       /* ec7 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  Directly to the west large mountains are visible protruding from\n"+
"the pale brown ground.  They loom in the darkness which surrounds\n"+
"you in every direction.  Sands are whipping around you as the wind\n"+
"whips overhead.  The ground is littered with small rocks.\n";
  items=({
  "mountains",
"The towering mountains impede passage to the west.  They are hidden\n"+
"amongst the darkness and the windy sands.  The climb high over your\n"+
"head, into the swirling sky above",
  "sky",
"The multitextured sky swirls above you as the winds cut through it",
  "ground",
"The ground is dry and cracked, covered by small rocks and sand.  It\n"+
"doesn't look as though life has existed here in ages",
  "sand",
"Sand is all around you, lying at your feet and blowing through the\n"+
"air.  The winds are relatively strong here",
  "sands",
"Sands are all around you",
  "wind",
"Wind is whipping all around you, kicking up the sand",
  "rocks",
"The small rocks that are scatter across the ground roll slightly as\n"+
"the strong winds push up against them.  They look identical to the\n"+
"flat ground",
  });
  dest_dir=({  "/players/zeus/desert/r/ec3.c", "north",
               "/players/zeus/desert/r/ec8.c", "east",
               "/players/zeus/desert/r/ec12.c", "south",  });
 }
}

void init(){
  ::init();
  add_action("search_cmd", "search");
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"
