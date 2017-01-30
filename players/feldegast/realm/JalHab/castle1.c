#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This was once the castle's courtyard, but now the soldiers of\n\
time have torn down the east and west wings.  Only the main keep to\n\
the north still stands.  To the south, a low wall overlooks the\n\
cliff's edge.\n";
  items=({
    "courtyard", "The yard is lined on three sides by the ruins of the castle\n"+
                 "and on the south side by the edge of the cliff",
    "keep","The keep appears to be in relatively good shape compared to the\n"+
           "rest of the castle",
    "wall", "A crenelated wall overlooks the desert far beneath you",
    "cliff", "You think you can climb down the cliff when you want to 'leave'",
  });
  dest_dir=({
    "fake exit","leave",
    PATH+"castle2.c","north",
  });
}

void init() {
  ::init();
  add_action("cmd_leave", "leave");
}

int cmd_leave(string str)
{
  say(TPN+" climbs down the cliff.\n");
  move_object(TP,(object)MAP->query_location(1,4));
  say(TPN+" climbs down the cliff.\n");
  command("look",TP);
  return 1;
}
