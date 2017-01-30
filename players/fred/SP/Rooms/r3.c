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
"  You stand before a small school house.  You can hear the sound\n"+
"of laughter coming from within.  There are a few small trees in\n"+ 
"the school yard, and a jungle gym on a thick slab of concrete.\n";

items = ({
  "school",
  "The school building is small and made of a reddish brick", 
  "trees",
  "Some small trees are growing in the school yard.  They are just\n"+
  "starting to blossom", 
  "gym",
  "The jungle gym is just a series of bars and ropes for children\n"+
  "to play on",
  "concrete",
  "A cold hard piece of concrete",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r2.c","east",
  "/players/fred/SP/Rooms/r15.c","enter",
  });
}
