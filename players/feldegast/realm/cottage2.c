#include "def.h"
inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Bedira's Workroom";
  long_desc=
"    The second floor of this cottage appears to be a workshop\n"+
"of some sort.  A pair of tall workbenches, covered in assorted\n"+
"vials, jars and retorts.  A cluttered desk sits by the window\n"+
"which is opposite the fireplace on the south wall.  A ladder\n"+
"leads up to the roof.\n";
  items=({
    "workbenches","Solidly made oak tables that come up past waist-level and\n"+
                  "that're covered with assorted gadgets and doo-dads",
    "vials","It looks like somebody's making corn whiskey",
    "jars","It looks like somebody's making peanut butter",
    "retorts","It looks like somebody's making corn whiskey",
    "desk","A journal lies open on the desk.  You think you could read it",
    "window","The window offers a picturesque view of the mountain to the north",
    "fireplace","A stone fireplace with several large chunks of wood burning inside",
  });
  dest_dir=({
    PATH+"cottage3","up",
    PATH+"cottage1","down"

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
