inherit "room/room";       /* ec12 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The warm darkness of this place surrounds you and presses down on you\n"+
"like a weight.  The ground beneath you is flat and dry, bits of sand\n"+
"blow across it and through the air.  Off in the distance the outlines\n"+
"of large mountains of rock can occasionally be seen.  It seems like you\n"+
"could travel in any direction from here.\n";
  items=({
  "ground",
"The ground is dry and flat, cracked in many places.  Sand seems to\n"+
"drift over it as the wind blows by",
  "sand",
"Bits of sand are scattered over the flat ground.  They move about\n"+
"aimlessly, driven by the unseen wind",
  "cracks",
"Many small cracks decorate the ground beneath you.  You can tell by\n"+
"looking at them that the ground here has been terribly dry for years",
  "mountains",
"They are very hard to see through the darkness of the sky and the\n"+
"sand blowing through the air, but pieces of mountain are visible\n"+
"to the northwest and southwest",
  });
  dest_dir=({  "/players/zeus/desert/r/ec7.c", "north",
               "/players/zeus/desert/r/ec13.c", "east",
               "/players/zeus/desert/r/ec17.c", "south",
               "/players/zeus/desert/r/ec11.c", "west",  });
  }
 }

void init(){
  ::init();
  add_action("search_cmd", "search");
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

