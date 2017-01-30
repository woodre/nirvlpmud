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
     "   sp19\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/sp/sp22.c","south",
  "/players/francesco/roma/rooms/sp/sp16.c","north",
  "/players/francesco/roma/rooms/sp/sp20.c","east",
  "/players/francesco/roma/rooms/sp/sp18.c","west"
});

}


init(){
      ::init();
      }


