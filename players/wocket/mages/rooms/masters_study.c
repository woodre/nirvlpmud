#include "../defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=BLK+BOLD+"The Master's Study"+NORM;
  long_desc=
"Long description\n";
  dest_dir=({
    ROOMDIR+"tower6.c","leave",
  });
}
