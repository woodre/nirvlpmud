#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A Short Approach";
long_desc ="  The dark cold path continues to twist through the debris.\n"+
           "The faint covered trail is difficult to find. Tall trees\n"+
           "block the light and dead branches line the way.  The sound\n"+
           "of wild animals can be faintly heard.  The path seems to\n"+
           "continue to the east and southwest.\n";
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
  "/players/softly/winter/rooms/pond16.c","east",
  "/players/softly/winter/rooms/pond18.c","southwest",
  });
}
