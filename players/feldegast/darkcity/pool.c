#include "def.h"
inherit MYROOM;
reset(arg) {
  if(!present("screber"))
    move_object(clone_object(PATH+"Npc/schreber"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="A heated pool";
  long_desc=
"     Humidity fills the air of this domed chamber.  In the middle of\n\
this circular room is a deep pool of heated water.  There is a small\n\
locker room to the side for changing clothes and private\n\
discussions.\n";
  items=({
    "humidity","You try staring at it up close, but it keeps disappearing",
    "pool","A large pool of water about twenty-five feet across",
    "water","The water smells of chlorine",
    "room","A small locker room obscured by a curtain",
    "curtain","There's nobody behind it"
  });
  dest_dir=({
    PATH+"lobby2","up"
  });
}   
