#include "def.h"

inherit ROOM;

reset(arg) 
{
  if(arg) return;
  set_no_teleport(1);
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  This is a workroom, filled with solid wooden tables and alchemical\n\
aparrati.  The walls are covered with shelves filled with herbs and\n\
powders.  To the north is a storage room, and to the south is the\n\
kitchen.  A pair of glass doors lead out into the garden.\n";

  items=({
    "workroom", "reflexive",
    "tables", "The room has three solid wooden tables each approximately\n"+
              "three and a half feet high",
    "apparati", "They burn, froth, bubble, and stew in a productive manner",
    "walls", "They are covered with shelves",
    "herbs", "They appear to be herbaceous in a plant-like sort of way",
    "powders", "Each powder is carefully labeled in a jar",
    "doors", "A pair of glass doors lead out into the garden",
  });

  dest_dir = ({
    ROOMPATH+"storage","north",
    ROOMPATH+"garden1","east",
    ROOMPATH+"kitchen", "south",
  });
}

