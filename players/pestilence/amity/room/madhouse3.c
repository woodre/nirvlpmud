#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+BLU+"Front Room"+NORM+"";
long_desc =
  "    This is the front room of the house.  There are two lounge chairs\n"+
  "in the southeast and southwest corners.  There is a large television\n"+
  "in the northeast corner.  The room is in disarray.  End tables are\n"+
  "scattered all around.  Across the floor, Madison Street can be seen\n"+
  "through the broken doorway.\n";
set_light(1);

items = ({
"chairs","Two large blue and gray fluffy lounge chairs in the south corners",
"television","A fifty-inch big screen television in the northeast corner",
"northeast corner","A fifty-inch big screen television is here",
"southwest corner","A lounge chair is here",
"southeast corner","A lounge chair is here",
"lounge chairs","Two large blue and gray fluffy lounge chairs in the south corners",
"tables","End tables have been scattered across the floor, leaving them broken",
"end tables","End tables have been scattered across the floor, leaving them broken",
"carpet","The carpet is a flat brown carpet going from wall to wall",
"doorway","A doorway that leads back out to Madison Street",
"walls","The walls are painted blue",
"wall","The wall is painted blue",
});

dest_dir = ({
"/players/pestilence/amity/room/madison2.c","north",
"/players/pestilence/amity/room/mad3kitchen.c","west",
"/players/pestilence/amity/room/mad3bedroom.c","east",
});
}
