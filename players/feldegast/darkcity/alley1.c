#include "def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(0);
  set_pk(1);
  short_desc="An Alley";
  long_desc=
"     Shadows thankfully obscure most of the trash that litters this\n\
alley.  To the south is a busy street, and above you is a huge sign\n\
which you can't make out from down here.  A ladder leads up to a\n\
catwalk beneath it.\n";
  items=({
    "shadows","There is a street lamp just outside the alley, but\n"+
              "it cannot seem to penetrate the thick shadows of\n"+
              "this city",
    "trash","You can't see it through the shadows",
    "street","A crowded street thick with cars",
    "sign","You can make out bright yellow paint, but not much else",
    "ladder","A metal ladder leading up to the catwalk above you"
  });
  dest_dir=({
    PATH+"catwalk","up",
    PATH+"street1","south"
  });
}   
