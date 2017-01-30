#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("hunter")) 
  move_object(clone_object("players/softly/winter/hhunter"),this_object());

  if(arg) return;
set_light(1);

short_desc = "Frigid Path";
long_desc ="  The dark cold path continues through the undergrowth.\n"+
           "Tall trees block the light and it is difficult to see\n"+
           "in any direction.  The path seems to continue to the\n"+
           "east and west.\n";

items = ({
  "path",  "The path is difficult to locate amidst the undergrowth",
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees cover the path",
  "evergreens","Dense evergreens nearly cover the path",
  "undergrowth","Snarls of vines combine with dead tree branches",
  "branches","Broken branches and brambles cover what was once a trail",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond15b.c","east",
  "/players/softly/winter/rooms/pond17.c","west",
  });
}
