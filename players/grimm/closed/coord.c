#include "/players/grimm/closed/ords.h"
inherit "room/room";
reset(arg) {
  if(arg) return;
  short_desc="The coordinate room";
  long_desc="This is where the corrdinates to the cannon are stored.\n";
  set_light(1);
}

i_coord() {
  return i;
}

j_coord() {
  return j;
}

k_coord() {
  return k;
}
