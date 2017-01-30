#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/fireangel4.c"), this_object()); }
    if(!present("mane")){
  move_object(clone_object("/players/maledicta/ruins/mobs/shadowmane.c"), this_object()); }
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   The tunnel here is very narrow, its walls crudely cut and\n"+
"blackened.  Straight ahead to the south the tunnel seems to\n"+
"dead-end. To the north is a large dark room.\n";

items = ({
  "walls",
  "Blasted and formed from intense heat, they are shaped\n"+
  "closer together than the other tunnels in the network",
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r13.c","north",
  "/players/maledicta/ruins/rooms/r15.c","south",
});

}
