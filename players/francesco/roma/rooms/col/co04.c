#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Corridor within the Coliseum" ;
long_desc =
     "   This corridor inside the Coliseum has two passageways:  stairs and\n"+
     "arches.  The walls are made by red tuff, by white travertine and by \n"+
     "brown bricks, all very good building materials indeed.\n",

items = ({
 "stairs","The stairs are made by uneven tuff steps, they lead to the upper rings",
 "arches","The arches are about 15 feet high and 10 feet wide.\n"+
          "They allow people to easily flow back and forth",  
 "walls","The walls sustain the whole upper levels.  Some small marble friezes\n"+
         "are still visible on them, notwithstanding the past pillages",
 "travertine","The travertine is a type of stone, similar to marble",
 "bricks","They are piled up to form the walls",
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co03.c","south",
  "/players/francesco/roma/rooms/col/co11.c","north",
  "/players/francesco/roma/rooms/col/co201.c","up"
});

}


init(){
      ::init();
      }


