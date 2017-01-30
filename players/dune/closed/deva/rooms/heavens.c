#include "std.h"

#include "/players/dune/closed/deva/def.h"

init() {
   add_action("church","church");
    add_action("lockers","lockers");
  set_light( 1);
}

short() { return "The Heavens"; }

long() {
  write("\n  This is the Heavens.\n\n");
  return 1;
}

lockers() {
  TR("/players/catwoman/tl.c",TPN+" flies down from the Heavens.\n");
  MO(TP,"/players/catwoman/tl.c");
  command("look",TP);
  TR(TO,TPN+" left to the lockers.\n");
  return 1;
}

church() {
  TR("/room/church",TPN+" flies down from the Heavens.\n");
  MO(TP,"/room/church");
  command("look",TP);
  TR(TO,TPN+" left to the church.\n");
  return 1;
}

