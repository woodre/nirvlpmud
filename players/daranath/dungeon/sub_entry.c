#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/dungeon/"
#define MOVE this_player()->move_player
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" ("+BOLD+BLK+"Dark Dungeon"+NORM+")");
long_desc=
"Daylight cascades down from above, illuminating this small chamber. Dark grey\n"+
"stone forms three of the four walls here, with a large marble doorway sitting\n"+
"in the forth wall. You are unable to see through the doorway, as the daylight\n"+
"doesn't seem to penetrate within. An iron rung ladder leads back to the\n"+
"city, a seemingly new addition to this ancient room.\n";

items=({
"daylight","Daylight steams through the opening in the ceiling illuminating this\n"+
     "chamber. During the evening, no light would be available at all",
"chamber","The small, square chamber has dark grey stone walls and a large doorway\n"+
     "in the northern wall",
"wall","The dark grey stone of the walls are dusty and rather old",
"walls","The dark grey stone of the walls are dusty and rather old",
"doorway","The marble of the doorway seems out of place here",
"marble","The doorway is made of pure marble, imported from another land",
"light","The only light source is the daylight coming from above",
"daylight","The only light source is the daylight coming from above",
"city","You are currently beneath the city of Qual'tor, near the southgate",
"room","This ancient room was built long ago, its purpose long forgotten",
"ladder","The iron rung ladder leads back to the city itself.\n"+
     "You could probably "+HIR+"climb"+NORM+" back to the surface",
    });

    dest_dir=({
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("move_back","back");
add_action("move_forward","forward");
}

search(){
write("The entrance to the Dark Dungeon has seen a number of heroes come and go.\n"+
      "Many of thier footprints end here, the heroes too afraid to actually enter.\n"+
      "the dungeon itself...\n");
  say(tp +" searches the area.\n");
 return 1;
}

move_forward(){
write("You move forward into the Dark Dungeon.\n");
MOVE("into the Dark Dungeon#"+ROOT+"doors.c");
return 1;
}

move_back(){
write("You head back within the Dark Dungeon.\n");
MOVE("back from the Dark Dungeon#"+ROOT+"entry.c");
return 1;
}
