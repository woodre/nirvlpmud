inherit "room/room";       /* ec1 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The darkness surrounds you here, presses down on you like a blanket\n"+
"of warmth.  To the north a large mountainous wall climbs into the sky.\n"+
"To the west a large pile of rock and debris highlights the desert.  A\n"+
"few boulders are scattered around, mostly to the east.  Smaller rocks\n"+
"are scattered amongst the sand.  The ground is dry and cracked.\n";
  items=({
  "darkness",
"The darkness is all around you.  You almost feel protected by it.\n"+
"You feel as though you could travel to the east or south from here",
  "wall",
"The wall of rock is dry and cracked.  It is hard to determine just what\n"+
"caused such a violent wrenching of the land.  There is no way to scale\n"+
"the wall.  It continues on from here to the east",
  "rock",
"The rock is brown and completely dry.  Many small cracks can be seen in it",
  "pile",
"This is an extremely large pile of boulders and rocks.  All of it is\n"+
"made from the same pale brown rock, and is extremely dry.  The wind\n"+
"is causing the sandier parts to scatter away",
  "sand",
"The ground is covered by a layer of sand.  The wind is blowing it all\n"+
"around.  Sand seems to be perpetually carried through the air, which\n"+
"has a tendency to hamper your vision",
  "debris",
"It is a pile of broken pieces of rock and sand",
  "rocks",
"Many small rocks are scattered about the floor of the desert here.\n"+
"They all look similar to the boulders and the pile of rock",
  "boulders",
"There are also some larger boulder shaped rocks here.  Most of them\n"+
"are to the east.  They are brown and look very dry, however they are\n"+
"far too heavy to be effected by the wind",
  "ground",
"The ground is very flat, dry and cracked.  It is coated by a layer of\n"+
"small sand and little rocks.  It doesn't look like life has grown here\n"+
"in many years",
  });
  /*
  dest_dir=({  "/players/zeus/desert/r/ec2.c", "east",
               "/players/zeus/desert/r/ec5.c", "south",  });
  */
 }
}

void init(){
  ::init();
  add_action("east_dir", "east");
  add_action("south_dir", "south");
  add_action("search_cmd", "search");
}

east_dir(){
  write("You walk east into the darkness...\n\n");
  this_player()->move_player("east#/players/zeus/desert/r/ec2.c");
  return 1;
}

south_dir(){
  write("You walk south into the darkness...\n\n");
  this_player()->move_player("south#/players/zeus/desert/r/ec5.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"


