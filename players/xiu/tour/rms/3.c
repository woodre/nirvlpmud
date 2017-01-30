#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "NirvanAH Music Festival";
long_desc =
" A clearing stretches for 20 or so yards in any direction.\n"+
" Patches of heaviy trampled grass sit in small brown patches,\n"+
" footprints sightly etched into the dirt.\n"+
"Lights shine from the stage farther north.\n";
items = ({
"grass",
"Matted, unattractive grass",
"footprints",
"Barely visible boot footprints",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"dirt",
"Red dirt from more southern climates",
  });

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
dest_dir = ({
"/players/xiu/tour/rms/4.c","north",
"/players/xiu/tour/rms/2.c","south",
"/players/xiu/tour/rms/e3.c","east",
"/players/xiu/tour/rms/w3.c","west",
"/players/xiu/tour/rms/e4.c","northeast",
"/players/xiu/tour/rms/w4.c","northwest",
"/players/xiu/tour/rms/e2.c","southeast",
"/players/xiu/tour/rms/w2.c","southwest",
  });
}
