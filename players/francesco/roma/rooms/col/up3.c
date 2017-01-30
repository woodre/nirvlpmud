#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Stairs within the Coliseum" ;
long_desc =
     "   Along the stairs of the Coliseum, which connect the basement to\n"+
     "the medium ring.  The steps are steep and a handrail helps to move.\n",

items = ({
 "stairs","The stairs are made by uneven tuff steps",
 "steps","The steps are about one feet high",
 "handrail","Nothing else than a wooden bar held on the walls by some nails",
   });

dest_dir = ({
  "/players/francesco/roma/rooms/col/co301.c","up",
  "/players/francesco/roma/rooms/col/co03.c","down"
});

}


init(){
      ::init();
      }


