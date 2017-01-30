#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(!random(6) && !present("cactus"))
    move_object(clone_object(MON_PATH+"cactipod"),this_object());
  if(arg)return;
  set_light(1);
  short_desc=YEL+"Jal-Hab Desert"+NORM;
  long_desc=
"  The vast desolation of the Jal-Hab desert spreads out before you\n\
in all directions.  An inconstant wind blows across the desert,\n\
moving and shaping the gritty sand into hills and valleys.  You spot\n\
a few scraggly bushes and cactii, but nothing that could provide\n\
sustenance.\n";
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
}

