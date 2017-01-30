inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A very small entry hall";
  long_desc=
"You are in a very small, square-shaped room, the only features of which\n"+
"are the stairs and the door in the north wall, to the west, and east,\n"+
"respectively.  The stairs and floor look to be made of wood, but the door,\n"+
"for some reason, is ironbound.\n";
  items= ({
    "room","Yes, you're standing in a room",
    "stairs","Wooden stairs, used to get to the first floor",
    "door","An oak door, reinforced by iron.  This would be a very difficult\n"+
           "door to break down",
    "floor","The floor is solid, but stained, as if never cleaned",
  });
  dest_dir= ({
    HROOM+"dojomain","down",
    HROOM+"loftent","north",
  });
}
