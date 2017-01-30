inherit "room/room";       /* ec2 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  You are next to a large wall of brown rock that climbs almost straight\n"+
"into the sky to the north.  It is massive and prevents travel in that\n"+
"direction.  Numerous large boulders are scattered about the area.  The\n"+
"sand is blowing all around you.  You feel the warmth from the desert\n"+
"and want to embrace the darkness.\n";
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
  dest_dir=({  "/players/zeus/desert/r/ec3.c", "east",
               "/players/zeus/desert/r/ec6.c", "south",  });
  }
 }

void init(){
  ::init();
  add_action("west_dir", "west");
  add_action("search_cmd", "search");
}

west_dir(){
  write("You walk west into the darkness...\n\n");
  this_player()->move_player("west#/players/zeus/desert/r/ec1.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

