/*

[Hall 20], North [hall 1], south [hall 23]

@@@@@@@@@@@@@@@@@@@@@
@|--------+---------@
HIK+"@"+HIW+"X"+HIK+"@@@@@@@@"+HIW+"|"+HIK+"@@@@@@@@"+HIW+"|"+HIK+"@"+NORM
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

#define NORTH "hall1"
#define SOUTH "hall23"
#define EAST "hall"
#define WEST "hall"

void reset(int arg) {

  if (!present("npc"))
    MOND->populate_monsters(this_object());

  if (arg)
    return;

  set_light(-10);
  short_desc = HIK+"The Demon Chamber ["+NORM+RED+"Blood Quarter"+HIK+"]"+NORM;
  long_desc=

    MAP1+"                   "+RED+"The Blood Quarter"+NORM+"\n"+
    MAP2+NORM+DESCD->get_long_desc(1)+
    HIK+"@"+HIW+"X"+HIK+"@@@@@@@@"+HIW+"|"+HIK+"@@@@@@@@"+HIW+"|"+HIK+"@"+NORM+DESCD->get_long_desc(2)+
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