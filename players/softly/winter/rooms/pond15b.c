#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Frigid Turn";
long_desc ="  The densely covered path turns sharply.  Dead branches\n"+
           "and downed trees cover the faint trail.  The light is very\n"+
           "dim making it difficult to see in any direction.  The path\n"+
           "seems to continue to the south and west.\n";

items = ({
  "path",  "The path is difficult to locate amidst the undergrowth",
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees cover the path",
  "evergreens","Dense evergreens nearly cover the path",
  "undergrowth","Snarls of vines combine with dead tree branches",
  "branches","Broken branches and brambles cover what was once a trail",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond15.c","south",
  "/players/softly/winter/rooms/pond16.c","west",
  });
}
