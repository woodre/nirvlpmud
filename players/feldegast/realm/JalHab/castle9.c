#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This cool dry cave has recently been rehabitated.  Fresh wooden\n\
beams have been used to shore up a tunnel in the back and it appears\n\
that a great deal of rubble has been removed recently.\n";
  items=({
    "cave", "reflexive",
    "beams", "These 4x4 beams look like they've been cut recently",
    "tunnel", "It appears to lead further into the mesa",
    "rubble", "There are traces that a great deal of rubble has been removed\n"+
              "from the tunnel to make passage possible",
  });
  dest_dir=({
    "fake exit", "out",
    PATH+"castle10.c","north",
  });
}

void init() {
  ::init();
  add_action("cmd_leave", "out");
  add_action("cmd_leave", "leave");  
}

int cmd_leave(string str)
{
  say(TPN+" leaves the cave.\n");
  move_object(TP,(object)MAP->query_location(1,4));
  say(TPN+" climbs down the cliff.\n");
  command("look",TP);
  return 1;
}
