inherit "room/room";
#include "DEFS.h"

reset(arg) {
  if(arg) return;
set_light(-3);

short_desc = HIR+"N"+NORM+"osferatu "+HIR+"G"+NORM+"uild "+HIR+"O"+NORM+"ffice";
long_desc =
  "A small, rectangular room of solid, dark rock surrounds you.  Cut\n"+
  "into the wall is an opening.  A large desk sits in the middle of\n"+
  "the room with a comfortable couch in front of it and a high-backed\n"+
  "chair sits behind the desk. An ornately framed picture adorns the\n"+
  "the wall behind the desk.\n";

items = ({
  "plate","A small name plate with the name "+HIR+"[ Eurale ]"+NORM+" on it",
  "picture","Nooneelse and Eurale dressed in their finest atire",
  "opening","A fireplace to warm the room.  Remnants of ash remain\n"+
            "as reminders of fires long gone out",
  "desk","A solid, stone structure with a highly polished top. Attached\n"+
         "to the front is a small plate",
  "couch","A comfortable, overstuffed couch covered in silk",
  "chair","Wooden and worn, a grand chair that has seen better days",
});

dest_dir = ({
  "/room/church","church",
  "/players/eurale/RMS/warp","warp",
  "/players/eurale/VAMPIRES/RMS/vgent","down",
});

}
