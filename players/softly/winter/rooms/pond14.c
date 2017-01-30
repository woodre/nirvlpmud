#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winter Path";
long_desc ="  The path continues through the undergrowth.  Dead branches\n"+
           "and downed trees cover the faint trail.  Tall evergreens\n"+
           "block the light making the path treacherous.  The path seems\n"+
           "to continue to the northeast and west.\n";

items = ({
  "path",  "The path is difficult to locate amidst the undergrowth",
  "trail", "Traces of a trail seem to lead west and northeast",
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees cover the path",
  "evergreens","Dense evergreens nearly cover the path",
  "undergrowth","Snarls of vines combine with dead tree branches",
  "branches","Broken branches and brambles cover what was once a trail",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond15.c","northeast",
  "/players/softly/winter/rooms/pond13.c","west",
  });
}
