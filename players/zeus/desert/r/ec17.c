inherit "room/room";       /* ec17 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The warmth of the desert along with the darkness presses down on  you\n"+
"light a blanket.  The sand is constantly being kicked up by the wind,\n"+
"making it difficult for you to see.  To the west small pieces of what\n"+
"appears to be a mountain of rock are occasionally visible.  The ground\n"+
"here is dry and cracked, scattered with rocks and sand.\n";
  items=({
  "desert",
"The desert is dark and hot",
  "darkness",
"A cloak of darkness hangs over the desert here.  It feels as though\n"+
"the darkness is trapping the heat in",
  "sand",
"A thin layer of sand coats the ground, while other sand blows through\n"+
"the air, obscuring your vision even more",
  "wind",
"The winds are blowing constantly here, whipping hot sand into you",
  "mountain",
"As you stare to the east, you can sometimes see what look like parts\n"+
"of a large mountain.  They quickly vanish among the sands however",
  "ground",
"The ground is dry and cracked, completely lifeless",
  "cracks",
"The ground is covered by small cracks",
  "rocks",
"Small rocks are scattered across the ground.  The smaller ones move\n"+
"slightly as the stronger winds push up against them.  They are the same\n"+
"pale brown color as the ground",
  "craters",
"The ground is mostly flat, however in some places there are small\n"+
"craters in it.  The rock around them is loose and starting to crumble\n"+
"away.  Most of them are just a few inches deep",
  "sky",
"The sky is a swirling mass of darkness",
  });
  dest_dir=({  "/players/zeus/desert/r/ec12.c", "north",
               "/players/zeus/desert/r/ec18.c", "east",
               "/players/zeus/desert/r/ec21.c", "south",  });
  }
 }

void init(){
  ::init();
  add_action("west_dir", "west");
  add_action("search_cmd", "search");
}

west_dir(){
  write("You walk west into the darkness...\n\n");
  this_player()->move_player("west#/players/zeus/desert/r/ec16.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

