inherit "room/room";       /* ec5 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The warmth of the desert seeps into you here, warming you in the\n"+
"darkness.  Very few features highlight the desert here.  To the west\n"+
"some protrouding rocks are visible.  Beneath you there are small rocks\n"+
"scattered among the sand.  The ground is very dry and cracked.  Darkness\n"+
"stretches on to the north.\n";
  items=({
  "darkness",
"The darkness of the desert is all around you.  It seems to stretch on\n"+
"in all directions from here, although strangely to the north",
  "rocks",
"To the west, large rocks protrude from the ground.  They are brown and\n"+
"lifeless, as is typical of this place.  They are hard to see for the\n"+
"sand that blows in front of you.  At your feet are various smaller rocks",
  "sand",
"A layer of sand coats the hard, dry desert floor.  As the wind blows sand\n"+
"is kicked up into the air",
  "ground",
"The ground is horribly dry and covered in cracks, as though it is begging\n"+
"for water.  It is covered by sand and small rocks",
  });
  dest_dir=({  "/players/zeus/desert/r/ec6.c", "east",
               "/players/zeus/desert/r/ec10.c", "south",  });
  }
 }

void init(){
  ::init();
  add_action("north_dir", "north");
  add_action("search_cmd", "search");
}

north_dir(){
  write("You walk north into the darkness...\n\n");
  this_player()->move_player("north#/players/zeus/desert/r/ec1.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"
