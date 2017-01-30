#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=YEL+"Luminous Grotto"+NORM;
  long_desc=
"  This is a tight little cul-de-sac deep beneath the earth.  By\n\
chance, this particular part of the myrmidar labyrinth is filled with\n\
fungi that cast a luminous glow.  The rocks and formations are covered\n\
with it.\n";
  items=({
    "fungi", "The fungi glows faintly in the dark",
    "rocks", "They are covered by the fungi",
    "formations", "They are covered by the fungi",
  });
  dest_dir=({
    PATH+"mound17.c","southwest",
  });
}
