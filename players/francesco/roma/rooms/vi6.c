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
     "   via6\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/vi7.c","east",
  "/players/francesco/roma/rooms/vi5.c","west",
  "/players/francesco/roma/rooms/arc/ar01.c","north"
});

}


init(){
      ::init();
      }

