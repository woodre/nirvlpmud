inherit "room/room";       /* ec10 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  You are surrounded by darkness here.  Sand is blowing through the air,\n"+
"whipping around the rocks.  To the west is a peculiar stone archway.  On\n"+
"either side of it large piles of rock rest.  It is very hard to see very\n"+
"far in any direction.  The warmth of the desert presses down on you.\n";
  items=({
  "archway",
"The stone archway is made of the same dry, brown rock that is abundant\n"+
"here.  It leads to the west.  On either side of the archway are large\n"+
"piles of rock",
  "arch",
"The stone archway is made of the same dry, brown rock that is abundant\n"+
"here.  It leads to the west.  On either side of the archway are large\n"+
"piles of rock",
  "rock",
"The rock is brown and very dry.  Much of it is cracking",
  "ground",
"The ground is dry, flat and covered in cracks.  A thin coating of sand\n"+
"and small rocks cover it",
  "sand",
"A thin coating of sand rests upon the ground.  The wind kicks the sand up\n"+
"into the air, which makes it hard for you to see",
  "rocks",
"Many small rocks litter the ground",
  "piles",
"The piles of rock force you to walk beneath the archway if you want to go\n"+
"west from here.  They are quite mountainous",
  "darkness",
"The darkness is all around you",
  });
  dest_dir=({  "/players/zeus/desert/r/ec5.c", "north",
               "/players/zeus/desert/r/ec15.c", "south",
               "/players/zeus/desert/r/ec9.c", "west",  });
  }
 }

void init(){
  ::init();
  add_action("east_dir", "east");
  add_action("search_cmd", "search");
}

east_dir(){
  write("You walk east into the darkness...\n\n");
  this_player()->move_player("east#/players/zeus/desert/r/ec11.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"
