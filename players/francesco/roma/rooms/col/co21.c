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
     "   Atop of the stairs and at the entrance of the lower ring of\n"+
     "the Coliseum.  Through the front arch, it is possible to snoop\n"+
     "the spectators area. \n",

items = ({
 "stairs","The stairs are made by uneven tuff steps, they lead to the lower floor",
 "area","Lines and lines of stone seats",
 "arch","The arch is about 15 feet high and 10 feet wide.\n"+
        "It is the entrance to the lower ring",  
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co28.c","west",
  "/players/francesco/roma/rooms/col/co22.c","northeast",
  "/players/francesco/roma/rooms/col/co04.c","down"
});

}


init(){
      ::init();
      }


