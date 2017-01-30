inherit "room/room";       /* ec3 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  To the north a large wall of dry brown rock blocks passage.  Numerous\n"+
"large boulders are scattered around this area, blocking vision in many\n"+
"directions.  Sand is blowing around you quickly, helping to obscure your\n"+
"vision.  The darkness is thick here and seems to coat the sky.  The\n"+
"desert seems to stretch out from here in numerous directions.\n";
  items=({
  "wall",
"The rock wall climbs into the sky at almost a 90 degree angle, and is\n"+
"almost entirely smooth.  It seems to continue on to the east and west\n"+
"from here",
  "rock",
"The rock is brown and very dry.  All of it looks the same",
  "boulders",
"There are many large, brown boulders scattered around the desert here.\n"+
"Each is at least 8 feet tall, and make seeing off in the distance even\n"+
"harder.  You feel as though you could continue to the east, south or west",
  "sand",
"There is sand all around you.  A light coating of sand rests on the hard,\n"+
"dry rock surface of the desert, and a perpetual cloud of sand seems to be\n"+
"whipping around your body",
  "darkness",
"The darkness seems to lurk around you as though it is alive",
  "sky",
"The multilayered sky seems to twist and bend within itself as the winds\n"+
"perpetually cut through it",
  });
  dest_dir=({  "/players/zeus/desert/r/ec7.c", "south",
               "/players/zeus/desert/r/ec2.c", "west",  });
  }
 }

void init(){
  ::init();
  add_action("east_dir", "east");
  add_action("search_cmd", "search");
}

east_dir(){
  write("You walk east into the darkness...\n\n");
  this_player()->move_player("east#/players/zeus/desert/r/ec4.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"
