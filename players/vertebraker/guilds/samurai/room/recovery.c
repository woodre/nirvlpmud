#include "../def.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Recovery Room";
  long_desc=
"This is the arena's recovery room.  Type 'regenerate' to recover from a\n"+
"ghostly state.  To the east is a staircase leading back up to the coliseum.\n";

  dest_dir=({
    ROOMDIR+"dojo_arena","up"
  });
}
init(arg) {
  ::init();
  add_action("regenerate","regenerate");
}

regenerate() {
  return this_player()->remove_ghost();
}

query_no_fight() {
  return 1;
}
