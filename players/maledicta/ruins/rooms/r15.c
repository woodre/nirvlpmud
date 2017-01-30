#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
    if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/fireangel5.c"), this_object()); }
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   Following the tunnel you find that instead of a dead-end it veers\n"+
"sharply to the west, leading to a dark room.  A small trickle of vile\n"+
"black water drips from a crack in the blackened walls.  The tunnel also\n"+
"leads back to the north.\n";

items = ({
  "water",
  "Disgusting stagnant water that reeks of sulfur",
  "crack",
  "A small crack that has formed in the blackened wall",
  "walls",
  "Blackened from some unknown source of great heat, they seem\n"+
  "to have been formed by melting"
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r14.c","north",
  "/players/maledicta/ruins/rooms/r16.c","west",
});

}
