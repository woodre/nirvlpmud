#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "South Park";
long_desc =
"  You are heading towards the west end of the town.  You can make\n"+
"out the shape of a larger building to the west.  There are some\n"+ 
"people walking along the sidewalk on the other side of the street.\n";

items = ({
  "building",
  "You're not quite positive but it looks to be a school house", 
  "people",
  "They are just walking along without a care in the world.  They\n"+
  "hardly notice you", 
  "sidewalk",
  "The sidewalk is gray and old.  There are a few small bugs hiding\n"+
  "in between the cracks",
  "bugs",
  "They are hiding in the cracks for shelter from people passing by",
  "street",
  "The street is full of people trying to get where they need to be",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r1.c","east",
  "/players/fred/SP/Rooms/r3.c","west",
   });
}
