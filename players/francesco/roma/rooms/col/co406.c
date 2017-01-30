#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Upper ring of the Coliseum" ;
long_desc =
     "   The upper ring of the Coliseum is more than a hundred 60 feet above\n"+
     "the arena and therefore the view of it is weak.  It is divided into\n"+
     "five segments, totalling about 35,000 seats.\n",

items = ({
 "arena","The elliptical area in the center of the Coliseum",
 "segments","They are indicated by thin marble walls",
 "seats","The seats on this ring are merely lines of tuff, \n"+
         "with the shape of backless benches",
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co407.c","north",
  "/players/francesco/roma/rooms/col/co405.c","southwest"
});

}


init(){
      ::init();
      }


