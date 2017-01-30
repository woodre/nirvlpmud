#include "/players/feldegast/defines.h"
inherit "obj/corpse";

  reset() {
  }
  init() {
    ::init();
    add_action("cmd_reincarnate","reincarnate");
  }
cmd_reincarnate() {
  if(this_player()->query_real_name()!=name) return 0;
  write("You carefully step back into your body.\n");
  this_player()->remove_ghost();
  move_object(this_object(),this_player());
  destruct(this_object());
  return 1;
}
long(str) {
  if(this_player() && this_player()->query_real_name()) {
    write("You can <"+HIM+"reincarnate"+NORM+"> yourself with your corpse.\n");
  }
  ::long(str);
}
