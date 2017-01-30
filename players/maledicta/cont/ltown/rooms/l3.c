#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object guard;
object civ;

reset(arg) {
if(!present("cont_lizardguard", this_object())){
guard = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
	move_object(guard, this_object());
}
if(!present("cont_lizardman", this_object())){
civ = clone_object("/players/maledicta/cont/ltown/mobs/lcivilian.c");
	move_object(civ, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "The village of "+HIG+"Terk'ula"+NORM+"";
long_desc =
"  You stand before the public well of the village. Here\n"+
"numerous villagers come to gather water and gossip. The\n"+
"road continues to the north and south, and to the east\n"+
"and west are mud huts.\n";

items = ({
  "street",
  "A dirt road that leads through the center of town",
  "well",
  "A very wide stone well with a wooden roof over it",
  "huts",
  "A small mud and wood hut that is probably a private residence.\n"+
  "It has a large pool of water that extends out of the backside",
  "road",
  "A dirt road that leads through the center of town",
  "fence",
  "A tall wooden wall that defends the village from attacks",
});

dest_dir = ({
  "/players/maledicta/cont/ltown/rooms/l5.c","north",
  "/players/maledicta/cont/ltown/rooms/hut2.c", "east",
  "/players/maledicta/cont/ltown/rooms/hut3.c", "west",
  "/players/maledicta/cont/ltown/rooms/l2.c", "south",
});

}

