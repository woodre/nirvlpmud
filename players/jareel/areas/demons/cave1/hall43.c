/*

[Hall 43], North [hall 0], South [hall 0]
          East  [hall 44], West [hall 0] 

@@@@@@@@@@@@@@@@@@@@@
@|--------+--------|@1,10,19
@|@@@@@@@@|@@@@@@@@|@20,21,22
@|------|@|@|------|@23,31,39
@@@@@@@@|@|@|@@@@@@@@40,41,42
HIK+"@"+HIY+"*"+HIW+"------|"+HIK+"@"+HIW+"|"+HIK+"@"+HIW+"|------"+HIY+"*"+HIK+"@"+NORM 43,51,59
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
#define EAST "hall44"
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
    MAP2+NORM+"     The cavern floor is covered with a red mucus bile\n"+
    MAP3+NORM+"     that sticks to anything it touches.  The bones and \n"+
    MAP4+NORM+"     weapons that lay in mucus, dissolve in its acidic\n"+
    MAP5+NORM+"     nature.  The walls are decorated with half eaten\n"+ 
    HIK+"@"+HIW+"X"+HIW+"------|"+HIK+"@"+HIW+"|"+HIK+"@"+HIW+"|------"+HIY+"*"+HIK+"@"+NORM+NORM+"     corpses, rotten and maggot ridden.  The air permeates\n"+
    MAP7+NORM+"     a methane death that lingers, and eats anything in\n"+
    MAP8+NORM+"     the area.\n"+
    MAP9+"\n"+
    MAP0+"\n"+
    MAPA+"\n";
	
  items = ({ ITEMS });

  dest_dir = ({

     "/players/jareel/areas/demons/cave1/"+EAST+"","east",
  });
}