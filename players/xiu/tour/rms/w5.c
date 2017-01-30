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
"There are no more tents as more people stream by.\n"+
"A sign points toward the stage to the east.\n"+
 "Security fencing stops movement to the north near the stage area.\n";

items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"fencing",
"A fence just high enough that it would be rather problematic to climb",
"people",
"All sorts of hippy looking people wander about",
  });

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
dest_dir = ({
"/players/xiu/tour/rms/w4.c","south",
"/players/xiu/tour/rms/5.c","east",
"/players/xiu/tour/rms/4.c","southeast",
});
}
