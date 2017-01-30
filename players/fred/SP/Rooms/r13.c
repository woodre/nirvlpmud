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
"  You now stand before the only bar in South Park.  There is\n"+
"loud music coming from inside and there are some intoxicated\n"+  
"individuals sitting on the curb blinking from the light outside.\n";

items = ({
  "bar",
  "South Park's only drinking establishment.  The boards used to\n"+
  "build it are all warped and look unstable", 
  "individuals",
  "These guys spent a little too much time in the bar last night",
  "curb",
  "It is a standard cement curb",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r12.c","south",
  "/players/fred/SP/Rooms/r14.c","enter",
  });
}
