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
" The bright summer sun creates illusionary waves in the air all around.\n"+
" Patches of grass are scattered about the scorched earth.\n"+
" Broken beer bottles and trash litter the ground sporadically.\n";
items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"bottles",
"Shattered beer bottles of an undistinguishable variety",
"trash",
"Various parts of paper and plastic strewn on the ground",
  });

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
dest_dir = ({
 "/players/xiu/tour/rms/e5.c","north",
 "/players/xiu/tour/rms/e3.c","south",
 "/players/xiu/tour/rms/4.c","west",
});
}
