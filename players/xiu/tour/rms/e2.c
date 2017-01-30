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
" A tattered rain shelter is set up next to a truck.\n"+
" Dust cakes the cars and trucks parked here in the 'lot'.\n"+
"People are crowded around a nitrious oxide tank.\n";


move_object(clone_object("/players/xiu/tour/mobs/multihip"), this_object());
items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"tank",
"A large tank used to fill balloons with nitrious oxide",
"cars",
"Various cars, some with phish bumper stickers",
"trucks",
"Dusty trucks, some with grateful dead stickers.",
"truck",
"A pickup truck with a strange paint job.",
  });

dest_dir = ({
"/players/xiu/tour/rms/e3.c","north",
"/players/xiu/tour/rms/e1.c","south",
"/players/xiu/tour/rms/2.c","west",
"/players/xiu/tour/rms/1.c","southwest",
});
}
