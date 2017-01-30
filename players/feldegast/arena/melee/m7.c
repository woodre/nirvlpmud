#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=GRN+"Swamp"+NORM;
  long_desc=
"  Lillypads cover a pond in the middle of this muddy bog.  Cattails\n"+
"and brown ugly roots spring up from the fetid water.  To the north\n"+
"you see hills and mountains, and to the east the land rises.\n";  
  items=({
    "lillypads","Green, circular plates float on the water of the pond",
    "pond","A flat circle of particularly deep water in this swamp",
    "cattails","A strange plant with an odd-looking 'cattail' on top of the stalk",
    "roots","Ugly brown roots that poke up to become ugly brown plants",
  });
  dest_dir=({
    PATH+"m4","north",
    PATH+"m8","east",
  });
}
long(str) {
  if(str=="hills") view_room(PATH+"m4");
  else
  ::long(str);
}
init() {
  ::init();
  add_action("mired","north");
  add_action("mired","east");
}
mired(str) {
  if(TP->query_attrib("ste")-random(25) > 5) {
    ::cmd_move(str);
    return 1;
  }
  write("You trip on a root and fall in the mud.\n");
  say(TPN+" trips on a root and falls in the mud.\n");
  return 1;
}

