#include "def.h"
inherit MYROOM;
reset(arg) {
  if(!present("book"))
    move_object(clone_object(PATH+"Npc/mrbook"));
  if (arg) return;
  set_light(0);
  short_desc=BLU+"The Central Chamber"+NORM;
  long_desc=
"     This is the inner chamber of the Strangers' dark empire, a\n\
massively scaled room with a vaulted ceiling and surrounded by viewing\n\
galleries.  At one end of the room is the face of of some giant cast\n\
in iron, behind which is the mechanism used to stop and start the\n\
city.  On the other side of the room is a huge globe, the focus of the\n\
Strangers' tuning which they useto warp the city to fit their\n\
needs.\n";
  items=({
    "ceiling","It is concealed in shadows",
    "galleries","Row upon row of viewing galleries filled with strangers",
    "face","A thin seam splits through the center of the giant iron face",
    "globe","A huge spherical piece of machinery swirling with young skyscrapers\n"+
            "and houses being prepared to sprout up onto the streets above"
  });
  dest_dir=({
    PATH+"ug2","south"
  });
}   
init() {
  ::init();
  add_action("cmd_open","open");
  add_action("cmd_use","use");
}
cmd_open(str) {
  if(str=="face") {
    write("You cannot open it.\n");
    return 1;
  }
}
cmd_use(str) {
  if(str=="mechanism" || str=="globe") {
    write("You cannot use that.  You do not have the power to tune.\n");
    return 1;
  }
}
