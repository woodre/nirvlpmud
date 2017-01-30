inherit "room/room";       /* ec20 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  To the south a massive wall of dry, brown rock climbs almost straight\n"+
"into the darkness above.  The wall is incredibly massive and blocks any\n"+
"travel in that direction.  There are a few large boulders around here.\n"+
"The sand is blowing strong, and as the wind hits your body you can feel\n"+
"the warmth of the desert distinctly.\n";
  items=({
  "wall",
"The rock wall climbs into the sky at almost a 90 degree angle, and is\n"+
"almost entirely smooth.  It seems to continue on to the east and west\n"+
"from here.  There is no way to scale it",
  "sky",
"The sky is dark and swirls slowly as the wind blows through it.  It\n"+
"seems to be made from numerous different types of gasses that run\n"+
"together like ink",
  "boulders",
"The massive boulders which are scattered around the desert floor here\n"+
"are blocking your vision in most directions.  They are made from the\n"+
"light brown, dry rock that is seen all around these parts",
  "sand",
"Sand is scattered all across the desert floor.  As the winds blow by\n"+
"sand is kicked up, whipping through the air.  It helps to obscure your\n"+
"vision",
  "darkness",
"The darkness is all around you.  As you stare off into the darkness,\n"+
"you feel as though you could continue to the east, south or west",
  });
  dest_dir=({  "/players/zeus/desert/r/ec21.c", "east",
               "/players/zeus/desert/r/ec16.c", "north",  });
  }
 }

void init(){
  ::init();
  add_action("west_dir", "west");
  add_action("search_cmd", "search");
}

west_dir(){
  write("You walk west into the darkness...\n\n");
  this_player()->move_player("west#/players/zeus/desert/r/ec19.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"
