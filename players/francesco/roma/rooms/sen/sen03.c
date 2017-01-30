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
     "   sen03\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/sen/sen09.c","west",
  "/players/francesco/roma/rooms/sen/sen08.c","northwest",
  "/players/francesco/roma/rooms/sen/sen07.c","north",
  "/players/francesco/roma/rooms/sen/sen06.c","northeast",
  "/players/francesco/roma/rooms/sen/sen05.c","east",
  "/players/francesco/roma/rooms/sen/sen02.c","south"
});

}


init(){
      ::init();
      }


