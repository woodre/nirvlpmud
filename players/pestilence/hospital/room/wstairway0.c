#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    The stairs end here.  It appears that this is the stairway that\n"+
  "leads into the basement.  Commonly the morgue and the labs\n"+
  "are found in the basement of hospitals.  It most likely is the\n"+
  "same here.  A door is to the south leading to another hallway.\n";
set_light(1);

items = ({
  "stairs","Cold hard cement stairs leading up.",
  "door","The door to the south, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/whall0.c","south",
  "/players/pestilence/hospital/room/wstairway.c","up",
});
}
init() {
  ::init();
add_action("south","south");
}

south(){
        write("The door appears to be locked.\n");
        return 1;
          }        