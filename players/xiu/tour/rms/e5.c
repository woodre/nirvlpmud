#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Nirvana Music Festival";
long_desc =
 "The stage area is farther to the north, but blocked by a fence.\n"+
"There are more people streaming toward the gate to the west.\n"+
 "There are no more tents as this area is concrete.\n";

items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"fence",
"A security fence stops movement to the stage to the north.",
  });

dest_dir = ({
"/players/xiu/tour/rms/5.c","west",
"/players/xiu/tour/rms/e4.c","south",
});
}
