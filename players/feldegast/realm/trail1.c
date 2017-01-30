#include "def.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A forest trail";
  long_desc=
"    This trail slopes steeply upward as it goes up the side of\n"+
"the mountain.  The pine and spruce trees become increasingly\n"+
"sparse as the trail becomes rockier and harder to follow.  The\n"+
"ground here is frozen solid and you see snow not far ahead.\n"+
"To the east, you see some smoke.\n";
  items=({
    "trail","A glamourized game trail really",
    "slope","The trail heads up the mountain at about a 40 degree angle",
    "trees","The pine and spruce trees stretch for miles in every direction.\n"+
            "It would be unwise to leave the game trail",
    "snow","You can't see any up-close here, but there seems to be alot of it\n"+
            "further up the mountain",
    "smoke","A small column of smoke rising above the trees to the east.  Possibly\n"+
            "from a warm fireplace"
  });
  dest_dir=({
    PATH+"trail2","north",
    PATH+"enter","south"

  });
}   
init() {
  ::init();
  add_action("search","search");
  add_action("east","east");
}
search(str) {
  write("Upon careful examination, you notice a hidden trail leading east.\n");
  return 1;
}
east() {
  write("You push aside a few bushes and follow a trail east.\n");
  TP->move_player("east#"+PATH+"outside");
  return 1;
}
