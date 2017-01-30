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
"Half-naked girls lie on towels, soaking up the sun.\n"+
"To the northwest, security for the stage screens people going into the stage.\n"+
"Vomit is sprayed all over a car and on the ground here.\n";

move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"girls",
"Hot ass, half naked girls, all oiled up.",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
  });

dest_dir = ({
"/players/xiu/tour/rms/e4.c","north",
"/players/xiu/tour/rms/e2.c","south",
"/players/xiu/tour/rms/3.c","west",
"/players/xiu/tour/rms/4.c","northwest",
"/players/xiu/tour/rms/2.c","southwest",
});
}
