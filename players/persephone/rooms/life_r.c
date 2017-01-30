inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg) {
 if(!arg) {
  set_light(1);
  short_desc="chapel";
  long_desc="This is a barren and stark room with no furnishings\n" +
            "by the feeling you think this is where dead people come\n" +
            "pray\n";
  dest_dir=({"players/persephone/rooms/chapela","west",
          });
 }
}
init(){
  ::init();
    add_action("pray","pray");
    add_action("pray","regenerate");
}
pray() {
    return call_other(this_player(), "remove_ghost", 0);
}
