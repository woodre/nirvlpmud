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
"  This is the far east section of South Park.  Birds are singing\n"+
"in the trees in front of the houses on either side of the street.\n"+  
"Kyle's house is off to the south and Stan's is north of here.\n";

items = ({
  "birds",
  "They are pearched in the top of the trees singing back and forth", 
  "trees",
  "These tall oak trees shade most of the front yard", 
  "houses",
  "The houses are on the side of the road.  You should see what's\n"+
  "inside of them",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r6.c","west",
  "/players/fred/SP/Rooms/r9.c","north",
  "/players/fred/SP/Rooms/r11.c","south",
  });
}
