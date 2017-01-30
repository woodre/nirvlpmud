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
"  This is the residential section of the town.  The sun is\n"+
"shining brightly and it is hard to see because of the glare\n"+  
"from the windows on all the houses.  Off to the south is\n"+
"Cartman's house and Kenny's house lies to the north.\n";

items = ({
  "sun",
  "The sun blinds you.  Didn't anyone ever tell you that you\n"+
  "aren't supposed to look at the sun", 
  "windows",
  "They are blinding from the glare.  You quickly look the other way", 
  "houses",
  "The houses are on the side of the road.  You should enter them",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r5.c","west",
  "/players/fred/SP/Rooms/r10.c","east",
  "/players/fred/SP/Rooms/r7.c","north",
  "/players/fred/SP/Rooms/r8.c","south",
  });
}
