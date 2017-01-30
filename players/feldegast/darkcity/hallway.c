#include "def.h"

inherit MYROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A motel hallway";
  long_desc=
"     This is a hallway in a seedy motel.  The lights here are dim\n\
and seem to project more shadows than they pierce.  There is one door\n\
open in this hallway and an elevator down the hall.\n";
  items=({
    "hallway","A long room with many doors",
    "lights","A few lightbulbs swinging from their fixtures",
    "shadows","The shadows make you feel gloomy and stylish",
    "door","There is a half-open door on the north side of\n"+
           "the hallway",
    "stairs","Conveniently, there're stairs on either end of the hallway"
  });
  dest_dir=({
    PATH+"murdroom","north",
    PATH+"lobby","down"
  });
}   
