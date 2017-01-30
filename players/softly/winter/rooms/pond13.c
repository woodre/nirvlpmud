#include "/players/softly/misc/ansi.h"

inherit "/room/room";
int i;
reset(arg) {
  if(!present("ermine")) {
    for(i=0;i<3;i++) {
  move_object(clone_object("players/softly/winter/ermine"),this_object());
    }
  }
  if(arg) return;
set_light(1);

short_desc = "Treacherous Path";
long_desc ="  The path twists through the undergrowth.  Dead branches\n"+
           "and downed trees cover the faint trail.  Tall evergreens\n"+
           "block the light making the path treacherous.  The path seems\n"+
           "to continue to the east and southwest.\n";

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
  "/players/softly/winter/rooms/pond14.c","east",
  "/players/softly/winter/rooms/pond12.c","southwest",
  });
}
