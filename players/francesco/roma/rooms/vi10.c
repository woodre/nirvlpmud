#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "New area, under construction" ;
long_desc =
     "   via10\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/vi11.c","east",
  "/players/francesco/roma/rooms/vi9.c","west"
});

}


init(){
      ::init();
      }


