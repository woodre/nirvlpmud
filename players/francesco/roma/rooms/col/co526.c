#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);


short_desc = "Velarium of the Coliseum" ;
long_desc =
     "   From the uppermost level of the Coliseum it is possible to have \n"+
     "a magnificent sight of the Roman Forum and of the downtown of Rome.\n"+
     "The arena appears very small from this height and no spectators are \n"+
     "allowed here.  There is a tough and high wodden pole, used to hold \n"+
     "the Velarium.\n",

items = ({
 "arena","The elliptical area in the center of the Coliseum",
 "forum","The Roman Forum is what in the past was the downtown of the city",
 "Forum","The Roman Forum is what in the past was the downtown of the city",
 "downtown","From this height, it is possible to look at the downtown of Roma\n"+
            "as far as the view can go",
 "pole","The wooden pole holds some wires connected to the Velarium",
 "velarium","The Velarium is an awning, it covers the whole Coliseum\n"+
            "to protect the spectators from the sunshine",
 "Velarium","The Velarium is an awning, it covers the whole Coliseum\n"+
            "to protect the spectators from the sunshine",
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co426.c","down"
});

}


init(){
      ::init();
      }


