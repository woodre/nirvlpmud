#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("stfolk")){ 
    move_object(clone_object("players/softly/algiers/mobs/folks.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Algiers";
  long_desc ="\n\
The small road ends abruptly at a copse of small trees\n\
and shrubs.  An almost invisible path seem to go directly\n\
through one of the tree trunks.  The road continues to the\n\
south where in the distance a soft green house is visible.\n";

  items = ({
    "road",
    "The brown earthen road is very dusty",
    "copse",
    "Densely interconnected trees and shrubs create a small\n\
but unexpected vista of green.  It is impossible to see in.",
    "trees",
    "Some of the trees have very odd leaves.  They are unfamiliar",
    "shrubs",
    "The shrubs almost seem to have been designed to intermingle\n\
with the trees.  They fill every available space",
    "path",
    "A tiny path begins at road's end and takes a straight line\n\
to one of the more odd of the trees.  If you tried to\n\
walk the path, you would smack right into a tree trunk",
    "house",
    "The small one story house is covered in clapboard\n\
and painted a soft green.  It has a white front porch",
    "trunks",
    "The gnarled tree has a thick black trunk that looks as\n\
if it were covered with soot",

  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road12.c","south",

  });
}
