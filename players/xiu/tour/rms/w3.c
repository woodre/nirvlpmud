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
"A single tree grows from the ground here,\n"+
"somehow managaing to survive with the chaos.\n"+
"Thistles spring from the ground,\n"+
"preventing people from perhaps trampling it.\n";

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"thistles",
"Sharp, spikey thistles that could dig into barefeet seamlessly.",
  });

dest_dir = ({
"/players/xiu/tour/rms/w4.c","north",
"/players/xiu/tour/rms/w2.c","south",
"/players/xiu/tour/rms/3.c","east",
"/players/xiu/tour/rms/4.c","northeast",
"/players/xiu/tour/rms/2.c","southeast",
});
}
