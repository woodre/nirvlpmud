#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Debris";
long_desc ="  Dense undergrowth and downed trees make passage very\n"+
           "difficult.  The air is bright and cold.  A large frozen\n"+
           "lake can be seen to the north and northwest. In the far\n"+
           "distance a small shack can be seen to the west.  The faint\n"+
           "traces of a trail can be seen to the east.\n";

items = ({
  "trail", "Traces of a trail seem to lead eastward",
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees dominate the landscape",
  "undergrowth","Snarls of vines combine with dead tree branches",
  "lake",  "The ice is quite thick covering the surface of the solidly\n"+
           "frozen lake. Looking closely there are a few small holes on\n"+
           "the surface",
  "air",   "The air is frigid",
  "debris","Broken branches and brambles cover what was once a trail",
  "shack", "A small shack has smoke rising above it.  It bears investigating",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond12.c","east",
  "/players/softly/winter/rooms/pond1.c","west",
  });
}
