#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Lower ring of the Coliseum" ;
long_desc =
     "   The lower ring of the Coliseum is very close to the arena and therefore\n"+
     "the view of it is nearly perfect.  It is divided in five segments:  one of\n"+
     "them is the so-called Podium, where the Emperor and his court were sitting.\n",

items = ({
 "arena","The elliptical area in the center of the Coliseum",
 "segments","They are indicated by thin marble walls",
 "podium","It is a covered area, with comfortable triclinia (couches) in it",
 "Podium","It is a covered area, with comfortable triclinia (couches) in it",   
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co24.c","northwest",
  "/players/francesco/roma/rooms/col/co22.c","south"
});

}


init(){
      ::init();
      }


