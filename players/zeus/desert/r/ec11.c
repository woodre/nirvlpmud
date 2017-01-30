inherit "room/room";       /* ec11 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The warmth of the desert surrounds you here.  Looking off into the\n"+
"darkness, it is hard to see many details of the area.  The sand is\n"+
"blowing swiftly all around you.  The ground is hard and dry, covered\n"+
"by a layer of sand and rocks.  The sky swirls with a darkness that is\n"+
"almost magical.\n";
  items=({
  "desert",
"You are in the middle of the desert.  It is hard to see very far in any\n"+
"single direction",
  "darkness",
"The darkness is all around you.  It is hard to tell in just which\n"+
"directions you can move",
  "sand",
"A layer of sand coats the ground.  As the wind blows it causes the sand\n"+
"to constantly shift.  The sand blows through the air",
  "rocks",
"Many small rocks are scattered among the sand on the ground",
  "ground",
"The ground is dry and hard, covered by rocks and sand.  Many small cracks\n"+
"are visible in it, as though it is begging for water",
  "sky",
"The sky seems to be made of many layers of dark gases which flow\n"+
"together as one.  The winds are blowing constantly, making the sky\n"+
"bend and twist.  There is no light coming from anywhere in the sky",
  "cracks",
"Many small cracks line the dry, flat ground",
  });
  dest_dir=({  "/players/zeus/desert/r/ec6.c", "north",
               "/players/zeus/desert/r/ec12.c", "east",
               "/players/zeus/desert/r/ec16.c", "south",  });
  }
 }

void init(){
  ::init();
  add_action("west_dir", "west");
  add_action("search_cmd", "search");
}

west_dir(){
  write("You walk west into the darkness...\n\n");
  this_player()->move_player("west#/players/zeus/desert/r/ec10.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"


