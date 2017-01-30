#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/fireangel3.c"), this_object()); }
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   Crawling down into the hole you find that the sides of the tunnel\n"+
"are smooth, as if the rock had melted then cooled as it ran.  The\n"+
"tunnel ends just a few feet away and opens up into darkness.  The\n"+
"tunnel also leads back up to the surface.\n";

items = ({
  "sides",
  "Smooth to the touch, what could have melted them in\n"+
  "this way?",
  "darkness",
  "You cannot see through it, especially from this angle",
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r10.c","up",
  "/players/maledicta/ruins/rooms/r12.c","down",
});

}
