#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Grassland";
  long_desc=
"  A brisk wind blows across this grassland, creating a rolling sea\n"+
"of green knee-length grass.  To the east you see a wagon sitting at\n"+
"the bottom of a hill.  To the north is a ruin, and to the west you\n"+
"see a swamp.\n";
  items=({
    "ruin","Who cares?",
    "wagon","Who cares?",
    "swamp","Who cares?",
  });
  dest_dir=({
    PATH+"m5","north",
    PATH+"m7","west",
    PATH+"m9","east"
  });
}
long(str) {
  switch(str) {
    case "wagon": case "hill": view_room(PATH+"m9");
                               break;
    case "ruin": view_room(PATH+"m5");
                 break;
    case "swamp": view_room(PATH+"m7");
                  break;
    default: ::long(str);
  }
}

