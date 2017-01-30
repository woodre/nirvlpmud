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
 "Tents are scattered all about as people walk to and fro.\n"+
"Dust fills the air, creating sheens of light that scatter all about.\n"+
"Trash litters the ground, which is somewhat muddy at parts.\n"+
"To the north, a stage is in the distance.\n";

items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"trash",
"Beer cans and random pieces of plastic and paper all over the ground",
"stage",
"A stage with elaborate lighting and huge speakers lies to the north",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
  });

 move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
dest_dir = ({
"/players/xiu/tour/rms/2.c","north",
"/players/xiu/tour/rms/e1.c","east",
"/players/xiu/tour/rms/w1.c","west",
});
}
