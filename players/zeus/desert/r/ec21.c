inherit "room/room";       /* ec21 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  To the south a large wall of dry brown rock blocks any passage in that\n"+
"direction.  Numerous large boulders are scattered around this area,\n"+
"helping to block your vision in many directions.  Sand is blowing\n"+
"around you quickly, making it even harder to see.  The darkness is\n"+
"thick here and seems to coat the sky.  The desert stretches out into\n"+
"the darkness from here in numerous directions.\n";
  items=({
  "wall",
"The rock wall climbs into the sky at almost a 90 degree angle, and is\n"+
"almost entirely smooth.  It seems to continue on to the east and west\n"+
"from here.  There is no way to get around it",
  "rock",
"The rock is brown and very dry.  All of it looks the same",
  "boulders",
"There are many large, brown boulders scattered around the desert here.\n"+
"Each is at least 8 feet tall, and make seeing off in the distance even\n"+
"harder.  You feel as though you could continue to the east or west",
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
  dest_dir=({  "/players/zeus/desert/r/ec17.c", "north",
               "/players/zeus/desert/r/ec20.c", "west",  });
  }
 }

void init(){
  ::init();
  add_action("east_dir", "east");
  add_action("search_cmd", "search");
}

east_dir(){
  write("You walk east into the darkness...\n\n");
  this_player()->move_player("east#/players/zeus/desert/r/ec22.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

