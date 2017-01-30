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
     "   sp08\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/sp/sp07.c","south",
  "/players/francesco/roma/rooms/sp/sp09.c","north",
  "/players/francesco/roma/rooms/sp/sp12.c","east",
  "/players/francesco/roma/rooms/sp/sp11.c","west"
});

}


init(){
      ::init();
      }


