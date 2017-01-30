/*

[Hall 22], North [hall 19], south [hall 39]

@@@@@@@@@@@@@@@@@@@@@
@|--------+---------@
@|@@@@@@@@|@@@@@@@@X@
@|------|@|@|------|@
@@@@@@@@|@|@|@@@@@@@@
@*------|@|@|------*@
@@@@@@@@@@|@@@@@@@@@@
@|------*@|@*------|@
@|@@@@@@@@|@@@@@@@@|@
@|--------+--------|@
@@@@@@@@@@@@@@@@@@@@@

*/

inherit "room/room";

#include "defs.h"

#define NORTH "hall19"
#define SOUTH "hall39"
#define EAST "hall"
#define WEST "hall"

void reset(int arg) {

  if (!present("npc"))
    MOND->populate_monsters(this_object());

  if (arg)
    return;

  set_light(-10);
  short_desc = HIK+"The Demon Chamber ["+NORM+RED+"Frozen Quarter"+HIK+"]"+NORM;
  long_desc=

    MAP1+"                   "+HIC+"The Frozen Quarter"+NORM+"\n"+
    MAP2+NORM+DESCD->get_long_desc(1)+
	HIK+"@"+HIW+"|"+HIK+"@@@@@@@@"+HIW+"|"+HIK+"@@@@@@@@"+HIW+"X"+HIK+"@"+NORM+DESCD->get_long_desc(2)+
    MAP4+NORM+DESCD->get_long_desc(3)+
    MAP5+NORM+DESCD->get_long_desc(4)+
    MAP6+NORM+DESCD->get_long_desc(5)+
    MAP7+NORM+DESCD->get_long_desc(6)+
    MAP8+NORM+DESCD->get_long_desc(7)+
    MAP9+"\n"+
    MAP0+"\n"+
    MAPA+"\n";
	
  items = ({ ITEMS });

  dest_dir = ({
     "/players/jareel/areas/demons/cave1/"+NORTH+"","north",
     "/players/jareel/areas/demons/cave1/"+SOUTH+"","south",
  });
}