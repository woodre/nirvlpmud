#include "def.h"
inherit "room/room";
reset(arg) {
  if (arg) return;
  move_object(clone_object(PATH+"ext-cot"),this_object());
  set_light(1);
  short_desc="Outside a cottage";
  long_desc=
"     This is a clearing surrounding a small two story cottage.\n"+
"A woodstack is against its side and smoke rises from its chim-\n"+
"ney.  To the west, a trail leads back into the woods.\n";
  items=({
    "chimney","Made out of carefully mortared rocks",
    "woodstack","A stack of wood piled up by the side of the house.  Looks\n"+
                "like somebody is ready for winter",
  });
  dest_dir=({
    PATH+"trail1","west"

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
