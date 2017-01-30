#include "../def.h"
inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc= ;
  long_desc=
  items=({
  });
  dest_dir=({

  });
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
