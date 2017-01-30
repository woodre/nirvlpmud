#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Middle ring of the Coliseum" ;
long_desc =
     "   The middle ring of the Coliseum is about 60 feet above the arena\n"+
     "and therefore the view of it is still good enough.  It is divided\n"+
     "into five segments, totalling about 25,000 seats where the spectators\n"+
     "could sit.\n",

items = ({
 "arena","The elliptical area in the center of the Coliseum",
 "segments","They are indicated by thin marble walls",
 "seats","The seats on this ring are merely lines of tuff, \n"+
         "with the shape of backless benches",
 "spectators","At an overall view, they dont look very elegant", 
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co314.c","west",
  "/players/francesco/roma/rooms/col/co312.c","east"
});

}


init(){
      ::init();
      }


