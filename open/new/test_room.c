#include "attribs.h"
inherit "/open/new/room";

reset(arg) {
set_light(1); short_desc = "A test room";
long_desc = "This is just a test rom.\n";
  dest_dir = ({"/room/church","church" });
  set_attribute(NO_TRANSFER_SP | NO_TRANSFER_HP);
  move_object(clone_object("open/new/test_mon"),this_object());
}
realm() { return "NT"; }
