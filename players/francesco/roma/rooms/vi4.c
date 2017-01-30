#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "A wide avenue" ;
long_desc =
     "   Along Via dei Fori Imperiali (Avenue of the Empire Forums) the\n"+
     "Roman Forum is well visible, with all its ancient buildings, temples, \n"+
     "the aqueducts, the triumphal arches.  The Coliseum is very nearby, \n"+
     "to the north. \n",

items = ({
 "buildings","Mostly made with red bricks, generally one or two flats high",
 "coliseum","The famous, huge Coliseum of the ancient Roma, a must see",
 "Coliseum","The famous, huge Coliseum of the ancient Roma, a must see",
 "temples","The ancient romans built several temples to honour their deities",
 "arches","The emperors built them and passed under them after coming back\n"+
          "from victorious conquest campaigns",
 "aqueducts","The roman aqueducts were made by endless lines of tall masonry\n"+
            "arches supporting the pipes.  They were able to pass over the hills.\n"+
            "A superb demonstration of engineering cleverness",
 "forum","The Roman Forum is what in the past was the downtown",
  });

dest_dir = ({
  "/players/francesco/roma/rooms/vi3.c","west",
  "/players/francesco/roma/rooms/vi5.c","east",
  "/players/francesco/roma/rooms/col/co001.c","north"
});

}


init(){
      ::init();
      }


