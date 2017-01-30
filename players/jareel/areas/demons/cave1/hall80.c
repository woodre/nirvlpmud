/*

[Hall 80], North [hall 77], South [hall 100]
          East  [hall 0], West [hall 0] 

@@@@@@@@@@@@@@@@@@@@@
@|--------+--------|@1,10,19
@|@@@@@@@@|@@@@@@@@|@20,21,22
@|------|@|@|------|@23,31,39
@@@@@@@@|@|@|@@@@@@@@40,41,42
@*------|@|@|------*@43,51,59
@@@@@@@@@@|@@@@@@@@@@60
@|------*@|@*------|@61,69,77
@|@@@@@@@@|@@@@@@@@X@78,79,80
@|--------+--------|@81,90,100
@@@@@@@@@@@@@@@@@@@@@

*/

inherit "room/room";

#include "defs.h"

#define NORTH "hall77"
#define SOUTH "hall99"
#define EAST "hall"
#define WEST "hall"

void reset(int arg) {

  if (!present("npc"))
    MOND->populate_monsters(this_object());

  if (arg)
    return;

  set_light(-1000);
  short_desc = HIK+"The Demon Chamber ["+NORM+RED+"Dark Quarter"+HIK+"]"+NORM;
  long_desc=

    MAP1+"                   "+RED+"The Dark Quarter"+NORM+"\n"+
    MAP2+NORM+DESCD->get_long_desc(1)+
    MAP3+NORM+DESCD->get_long_desc(2)+
    MAP4+NORM+DESCD->get_long_desc(3)+
    MAP5+NORM+DESCD->get_long_desc(4)+
    MAP6+NORM+DESCD->get_long_desc(5)+
    MAP7+NORM+DESCD->get_long_desc(6)+
    MAP8+NORM+DESCD->get_long_desc(7)+
    HIK+"@"+HIW+"|"+HIK+"@@@@@@@@"+HIW+"|"+HIK+"@@@@@@@@"+HIW+"X"+HIK+"@\n"+NORM+NORM+
    MAP0+"\n"+
    MAPA+"\n";
	
  items = ({ ITEMS });

  dest_dir = ({
     "/players/jareel/areas/demons/cave1/"+NORTH+"","north",
     "/players/jareel/areas/demons/cave1/"+SOUTH+"","south",
  });
}