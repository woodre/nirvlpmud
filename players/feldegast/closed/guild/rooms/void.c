#include "/players/feldegast/closed/guild/defines.h"

inherit ROOM;

short() {
  return short_desc;
}
reset(arg) {
  if(arg) return;
  short_desc="A place between the stars";
  long_desc=
"     Darkness surrounds this place, where no walls, nor floors exist.\n"+
"Stars twinkle in the distance, pinpoints of brightness all alone in\n"+
"the night.\n";
  set_light(1);
}
