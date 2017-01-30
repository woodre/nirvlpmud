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
     "   ar08\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/arc/ar07.c","south",
  "/players/francesco/roma/rooms/arc/ar09.c","west"
});

}


init(){
      ::init();
      }


