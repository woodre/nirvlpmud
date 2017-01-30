#include "defs.h"

inherit ROOM;

void reset(status arg) {
  ::reset(arg);

  if (arg)
    return;

  short_desc = YEL + "On a Drawbridge" + NORM + NORM;
  long_desc = (string)WAXFUNS->line_wrap("The great timbers of this drawbridge show no signs of wear or age, nor the strain of the travellers milling about.  A murky, forbidding moat lies beneath it, and a dirt road begins at the southern end.  The drawbridge continues to a gap in the vast castle walls that lie across the moat.\n");
  dest_dir = ({ FIELDS, "south"
     , RPATH + "portcullis.c", "north" });
  items = ({ "drawbridge", "It's constructed of vast timbers"
     , "timbers", "They show no signs of wear or age"
     , "moat", "Dark shapes move about under it's surface"
     , "shapes", "You can't make out any details other than that they are huge"
     , "surface", "You see dark shapes moving under the surface of the moat"
     , "travellers", "They pay you no mind"
     , "walls", "The sheer walls reach majestically into the sky"
     , "castle walls", "The sheer walls reach majestically into the sky"
    , "gap", "It's to the north"
     , "castle", "It lies at the end of the drawbridge, to the north"
     });
}
