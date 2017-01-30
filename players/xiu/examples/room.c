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
" Tents are scattered all about as people walk to and fro.\n"+
" Dust fills the air, creating sheens of light that scatter all about.\n"+
" Music thumps in the background and the contageous beat gives people a hop\n"+
" to their step.\n";

items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
  });

dest_dir = ({
"/players/xiu/workroom.c","home",
  });
}
