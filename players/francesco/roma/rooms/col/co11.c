#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "The arena of the Coliseum" ;
long_desc =
     "   The arena of the Coliseum spams about like a football field.\n"+
     "It has an elliptical shape and is paved with well pressed soil.\n",

items = ({
 "soil","Nothing else than pressed powder",   
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co04.c","south",
  "/players/francesco/roma/rooms/col/co12.c","east"
});

}


init(){
      ::init();
      }


