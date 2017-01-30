#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(arg)return;
  set_light(1);
  short_desc=YEL+"Jal-Hab Desert"+NORM;
  long_desc=
"  Rolling waves of sand span the desert as far as the eye can see.\n\
Ugly looking and poisonous plants dot the sand dunes.  A hot breeze\n\
makes the sand airborne and the gritty stuff gets into your clothing\n\
and chafes.\n";
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
}

