#include "defs.h"

inherit ROOM;

void reset(status arg) {
  ::reset(arg);

  if (arg)
    return;

  short_desc = YEL+"Portcullis"+NORM+NORM;
  long_desc = "An immense iron portcullis looms overhead.  To the east and west are openings into guard shacks that are apparently cut right into the seamless stone of the castle walls.  The walls stretch beyond sight into the sky.  A drawbridge spans a moat to the south.  The sounds of a busy marketplace emanate from the north.\n";
  long_desc = (string)WAXFUNS->line_wrap(long_desc);
  dest_dir = ({ RPATH+"on_bridge", "south"
    , RPATH+"main1.c", "north" });
  items = ({ "drawbridge", "A lowered drawbridge crosses a moat to the south"
    , "moat", "A lowered drawbridge spans it.  It's to the south"
    , "portcullis", "It appears to be a formidable defense"
    , "stone", "There are no discernible seams or markings on it at all"
    , "seams", "No discernible seams means that you can't see any"
    , "markings", "You don't see any"
    , "walls", "The tops of them can't be seen"
    , "openings", "The openings are closed right now"
    , "shacks", "They look as if they are cut into the walls themselves"
    , "guard shacks", "They look as if they are cut into the walls themselves"
    , "shack", "The guard shacks look as if they are cut into the walls themselves"
    });
}
