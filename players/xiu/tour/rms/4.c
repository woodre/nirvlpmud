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
 "Guys with neon sunglasses talk amoungst each other by coolers.\n"+
" Smoke rises into the air from  grills where food is cooking.\n"+
" The bright summer sun beats down creating a glare here.\n"+
" To the north lies the music stage.\n";

items = ({
"guys",
"Muscular men, some with shirts and some without.",
"smoke",
"Light white smoke from grills.",
"sun",
"Staring at the sun may cause eye damage!",
"stage",
"The music stage is farther to the north.",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
  });

 move_object(clone_object("/players/xiu/tour/mobs/chick.c"), this_object());
 move_object(clone_object("/players/xiu/tour/mobs/frat.c"), this_object());
dest_dir = ({
"/players/xiu/workroom.c","home",
"/players/xiu/tour/rms/5.c","north",
"/players/xiu/tour/rms/3.c","south",
"/players/xiu/tour/rms/e4.c","east",
"/players/xiu/tour/rms/w4.c","west",
"/players/xiu/tour/rms/e5.c","northeast",
"/players/xiu/tour/rms/w5.c","northwest",
"/players/xiu/tour/rms/e3.c","southeast",
"/players/xiu/tour/rms/w3.c","southwest",
  });
}
