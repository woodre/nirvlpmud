#include "../defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A small chapel";
  long_desc=
    "  This is a small chapel in the Crystal Tower.  Here, private\n"+
    "ceremonies can be performed in relative peace.  At the far\n"+
    "end of the room is a marble altar.  Behind it is the crest\n"+
    "of House Tulan.  There are a few rows of pews for spectators.\n";
  items=({
    "pews","Cool marble benches that you could sit on",
    "altar","A simple altar made of marble",
    "crest",
      "The crest is an argent on azure chevron with a wolf on one side\n"+
      "and the scales of justice on the other"
  });
  dest_dir=({
    ROOM_DIR + "crystal2.c", "south",
  });
}

init() {
  ::init();
  add_action("sit","sit");
}

sit() {
  write("You sit on a pew.\n");
  say(TPN+" takes a seat.\n");
  return 1;
}
