/*
File: teleport.c
Author: feldegast
Date: 2/16/01
Description:
  A teleport chamber available via the midnight cloak which is on
Arien, Mistress of Ravens.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=GRN+"Nexus of Worlds"+NORM;
  long_desc=
"  This is an island floating in the void.  Grey emptiness surrounds\n\
it as far as the eye can see.  The top of the island is utterly flat\n\
and covered with marble tiles.  Interspersed at regular intervals\n\
along the curve of the island are gates leading to other worlds.\n\
\t\tchurch    allandria  turtleville\n\
\t\tryllian   qualtor    nirvana\n";
  items=({
    "island", "reflexive",
    "emptiness", "It looks like this:\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLike that",
    "eye", "I meant that figuratively.  There's not really an eye",
    "tiles", "The marble tiles are blue streaked with white",
    "gates", "The gates are several meters tall and constructed of marble",
  });
    
  dest_dir=({
    "/room/church", "church",
    "/players/feldegast/shrine.c", "allandria",
    "/players/wocket/turtleville/tville_fount", "turtleville",
    "/players/saber/ryllian/portal", "ryllian",
    "/players/daranath/qualtor/entry", "qualtor",
    "/room/forest10", "nirvana",
  });
  no_exits=1;
}

short() {
  return short_desc;
}

long(str) {
  if(!str) write(long_desc);
  else ::long(str);
}
