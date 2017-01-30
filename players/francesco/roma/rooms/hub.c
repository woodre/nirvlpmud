#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "The hub" ;
long_desc =
     "   Hub Room, used only by Fran (the test char).\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/vi1.c","enter",
  "/players/francesco/univ/rooms/bar2.c","exit"
});

}


init(){
      ::init();
      }


