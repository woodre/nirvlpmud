#include "../def.h"
inherit ROOM;
reset(arg) {
  if(!present("shopkeeper"))
    move_object(clone_object(PATH+"Haven/shpkpr2"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="Eagle's Claws";
  long_desc=
"    This immaculate shop is lined with racks of various weapons.\n"+
"Behind frosted windows you see thick iron bars, and the sturdy\n"+
"door looks like it could hold off an army until reinforcements\n"+
"arrived.  To the left of the door is a wooden counter where the\n"+
"shopkeeper usually sits.\n";
  items=({
    "racks","They've been knicked and scratched by hundreds of weapons\n"+
            "but they're still standing",
    "windows","You can't make out anything through the thick frosted windows",
    "bars","Thick bars made out of black iron",
    "door","A thick oak door with banded iron hinges and a bar",
    "counter","A sturdy counter for placing goods while they're being haggled over"
  });
  dest_dir=({
    PATH+"Haven/bronze1","east"
  });
}   
