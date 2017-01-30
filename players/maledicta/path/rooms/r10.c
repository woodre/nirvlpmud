#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a swampy area";
long_desc =
"  The ground here turns into a mush, with splotches\n"+
"of tall, thick grass scattered about.  Trees sag all\n"+
"about under the weight of water and moisture.  A path\n"+
"leads east and west.\n";  

items = ({
  "ground",
  "The ground here is mush",
  "grass",
  "Strands of swamp grass that rise up out of water and mud",
  "trees",
  "Sagging trees that almost looked depressed",
  "path",
  "A path that leads to the east and west",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r11.c","east",
  "/players/maledicta/path/rooms/r7.c","west",
});

}


