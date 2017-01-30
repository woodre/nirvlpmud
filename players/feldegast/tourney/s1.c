#include "def.h"

inherit AROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Cave"+NORM;
  long_desc=
1234567890123456789012345678901234567890123456789012345678901234567890
"  Light trickles through the dusty air of this limestone cave\n\
through a short, ascending tunnel that leads out into the open air.\n\
In the back of the cave, a
  dest_dir=({
    PATH+"m1","out",
  });
}
