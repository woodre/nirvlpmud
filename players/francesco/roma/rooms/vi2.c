#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "A small hill" ;
long_desc =
     "   Atop of this small hill it is possible to view the surrounding\n"+
     "buildings which are about the same height.  The lawns are well \n"+
     "maintained, the walkways are made with white tiny pebbles.  To \n"+
     "the east, hidden by tall oaks, it is barely visible the Coliseum.\n"+
     "Narrow stairs lead down the hill, towards the Coliseum.\n",

items = ({
 "lawns","The lawns are made by green grass, evenly cut very low",
 "buildings","Apartment buildings, four flats high",
 "coliseum","The famous, huge Coliseum of the ancient Roma, a must see",
 "Coliseum","The famous, huge Coliseum of the ancient Roma, a must see",
 "walkways","They cross all around the hill, making the walks easier",
 "oaks","The oaks are about twenty feet tall, with abundant foliage",
 "stairs","The stairs have also handrails to ease the descent",
 "pebbles","The pebbles are evenly distributed along the walkways",
});

dest_dir = ({
  "/players/francesco/roma/rooms/vi1.c","south",
  "/players/francesco/roma/rooms/vi3.c","down"
});

}


init(){
      ::init();
      }


