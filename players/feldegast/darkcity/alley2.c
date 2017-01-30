#include "def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(0);
  set_pk(1);
  short_desc="An Alley";
  long_desc=
"     Shadows thankfully obscure most of the trash that litters this\n\
alley.  This is an alley between a hotel and an automat.  To the south\n\
is a busy street.  A flight of stairs leads up the side of the automat\n\
to an apartment.\n";
  items=({
    "shadows","There is a street lamp just outside the alley, but\n"+
              "it cannot seem to penetrate the thick shadows of\n"+
              "this city",
    "trash","You can't see it through the shadows",
    "street","A crowded street thick with cars",
    "stairs","A flight of stairs that leads up to the second story\n"+
             "of the automat"
  });
  dest_dir=({
    PATH+"hookrm","up",
    PATH+"street3","south"
  });
}   
