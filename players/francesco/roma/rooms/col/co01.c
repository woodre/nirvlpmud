#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "A paved road" ;
long_desc =
     "   This is a typical ancient roman road.  The pavement is made by \n"+
     "large rectangular stones with a slight slope towards the sides.\n"+
     "Therefore, the rain water cannot stagnate in the middle.  To the \n"+
     "north the Coliseum is visible.\n",

items = ({
 "pavement","The pavement is uneven due to the irregularities of the stones",
 "stones","Each stone is about three by three feet wide.  They are well\n"+
          "levigated by the millennial use",
 "coliseum","The famous, huge Coliseum of the ancient Roma, a must see.  It is a\n"+
            "cylinder about 150 feet tall, with four floors.  Each floor is indicated\n"+
            "by a row of 80 arches running all around.  Its base is elliptical,  about\n"+
            "600 feet wide.  Most likely, in the past it could host about 75,000 sittings",
 "Coliseum","The famous, huge Coliseum of the ancient Roma, a must see.  It is a\n"+
            "cylinder about 150 feet tall, with four floors.  Each floor is indicated\n"+
            "by a row of 80 arches running all around.  Its base is elliptical,  about\n"+
            "600 feet wide.  Most likely, in the past it could host about 75,000 sittings",
   });

dest_dir = ({
  "/players/francesco/roma/rooms/col/co001.c","south",
  "/players/francesco/roma/rooms/col/co02.c","north"
});

}


init(){
      ::init();
      }


