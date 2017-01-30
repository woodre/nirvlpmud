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
"  This is the main road heading through South Park.  The sky is\n"+
"blue and the air is crisp.  This appears to be a very peaceful town.\n"+ 
"There are trees all around and animals scampering about searching\n"+
"for food.\n";

items = ({
  "road",
  "The road is made of smooth black pavement", 
  "sky",
  "The sky is a bright blue with hardly a cloud in sight", 
  "trees",
  "Tall trees shoot up from the ground towards the sky creating a nice shade",
  "animals",
  "Squirrels and Birds are running around looking for bits of food",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r2.c","west",
  "/players/fred/SP/Rooms/r4.c","east",
  "/players/fred/SP/Rooms/r12.c","north",
  "/players/fred/forest/Rooms/entrance.c","leave",
  });
}
