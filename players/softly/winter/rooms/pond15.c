#include "/players/softly/misc/ansi.h"

inherit "/room/room";
int i;
reset(arg) {
  if(!present("ermine")) {
    for(i=0;i<5;i++) {
  move_object(clone_object("players/softly/winter/ermine"),this_object());
    }
  }
  if(arg) return;
set_light(1);

short_desc = "Frigid Path";
long_desc ="  The dark cold path continues through the undergrowth.\n"+
           "Tall trees block the light and it is difficult to see\n"+
           "in any direction.  The path may continue to the north\n"+
           " and southwest.\n";
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
  "/players/softly/winter/rooms/pond15b.c","north",
  "/players/softly/winter/rooms/pond14.c","southwest",
  });
}
