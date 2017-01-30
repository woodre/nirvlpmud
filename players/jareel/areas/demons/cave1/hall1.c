/*

[Hall 1], east [hall 2], south [hall 20]

@@@@@@@@@@@@@@@@@@@@@
@X--------+---------@
@|@@@@@@@@|@@@@@@@@-@
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

#define NORTH "hall"
#define SOUTH "hall20"
#define EAST "hall2"
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
    HIK+"@"+HIW+"X--------+--------|"+HIK+"@"+NORM+DESCD->get_long_desc(1)+
    MAP3+NORM+DESCD->get_long_desc(2)+
    MAP4+NORM+DESCD->get_long_desc(3)+
    MAP5+NORM+DESCD->get_long_desc(4)+
    MAP6+NORM+DESCD->get_long_desc(5)+
    MAP7+NORM+DESCD->get_long_desc(6)+
    MAP8+"\n"+
    MAP9+DESCD->get_long_desc(7)+
    MAP0+"\n"+
    MAPA+"\n";
	
  items = ({ ITEMS });

  dest_dir = ({
     "/players/jareel/areas/demons/cave1/"+SOUTH+"","south",
     "/players/jareel/areas/demons/cave1/"+EAST+"","east",
  });
}