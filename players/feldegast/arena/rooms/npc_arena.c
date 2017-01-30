#include "/players/feldegast/defines.h"
#include "std.h"
status gate;
reset(arg) {
  if(arg) return;
}
init() {
  add_action("out","out");
  set_light(1);
  command("look",this_player());
}
short() {
  return "The Arena";
}
long() {
  write(
"     This is a private arena deep inside the coliseum.  It is a\n"+
"square room approximately 20 meters from wall to wall.  Guttering\n"+
"torches cast eary shadows and smoke about the room.  A gate in the\n"+
"south wall is the only way out.\n"+
"     There is one obvious exit: out\n"
  );
}
out(arg) {
    this_player()->move_player("out#/players/feldegast/arena/rooms/inner2");
    destruct(this_object());
    return 1;
}
/* The arena is a no teleport area. */
realm() { return "NT"; }
