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
" Cars are parked side by side with tents attatched at one side.\n"+
" The sun glimmers off the windshields of the cars.\n"+
" A man is passed out nearby in a puddle of puke.\n";
items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
  });

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
dest_dir = ({
"/players/xiu/tour/rms/w5.c","north",
"/players/xiu/tour/rms/w3.c","south",
"/players/xiu/tour/rms/4.c","east",
"/players/xiu/tour/rms/5.c","northeast",
"/players/xiu/tour/rms/3.c","southeast",
});
}
