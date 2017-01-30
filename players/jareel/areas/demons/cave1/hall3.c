/*

[Hall 3], North [hall 0], South [hall 0]
          East  [hall 4], West [hall 2] 

@@@@@@@@@@@@@@@@@@@@@
@|-X------+--------|@1,10,19
@|@@@@@@@@|@@@@@@@@|@20,21,22
@|------|@|@|------|@23,31,39
@@@@@@@@|@|@|@@@@@@@@40,41,42
@*------|@|@|------*@43,51,59
@@@@@@@@@@|@@@@@@@@@@60
@|------*@|@*------|@61,69,77
@|@@@@@@@@|@@@@@@@@|@78,79,80
@|--------+--------|@81,90,100
@@@@@@@@@@@@@@@@@@@@@

*/

inherit "room/room";

#include "defs.h"

#define NORTH "hall"
#define SOUTH "hall"
#define EAST "hall4"
#define WEST "hall2"

void reset(int arg) {

  if (!present("npc"))
    MOND->populate_monsters(this_object());

  if (arg)
    return;

  set_light(-10);
  short_desc = HIK+"The Demon Chamber ["+NORM+RED+"Blood Quarter"+HIK+"]"+NORM;
  long_desc=

    MAP1+"                   "+RED+"The Blood Quarter"+NORM+"\n"+
    HIK+"@"+HIW+"|-X------+--------|"+HIK+"@"+NORM+DESCD->get_long_desc(1)+
    MAP3+NORM+DESCD->get_long_desc(2)+
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
     "/players/jareel/areas/demons/cave1/"+EAST+"","east",
     "/players/jareel/areas/demons/cave1/"+WEST+"","west",
  });
}