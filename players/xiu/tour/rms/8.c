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
" The camping grounds continue to stretch in every direction.\n"+
" The main stage is closer now to the north.\n"+
" Music thumps in the background and the contageous beat gives people a hop\n"+
" A RV with an American flag sits parked nearby.\n";

items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"flag",
"The ole right white and blue",
  });

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
dest_dir = ({
"/players/xiu/tour/rms/6.c","north",
"/players/xiu/tour/rms/4.c","south",
"/players/xiu/tour/rms/e5.c","east",
"/players/xiu/tour/rms/w5.c","west",
"/players/xiu/tour/rms/e4.c","southeast",
"/players/xiu/tour/rms/w4.c","southwest",
  });
}
