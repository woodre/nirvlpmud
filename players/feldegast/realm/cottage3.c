#include "def.h"
inherit "room/room";
reset(arg) {
  object mage;
  if(!present("bedira")) {
    mage=clone_object("/players/feldegast/mon/bedira");
    move_object(mage,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A Cottage's Roof";
  long_desc=
"    The cottage's roof appears to be designed to act as an\n"+
"observation platform.  Pointing north, is a meter and a half\n"+
"long tube, possibly a telescope, fixed to the rail with a\n"+
"clamp.  Looming above the cottage to the north, is a mountain\n"+
"which appears to be the telescope's focus.\n";
  items=({
    "rail","A thick piece of wood at about waist level going around the edge\n"+
           "of the roof to prevent people from falling",
    "telescope","You look through the telescope and see a crater near the mountain's peak",
  });
  dest_dir=({
    PATH+"cottage2","down"

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
