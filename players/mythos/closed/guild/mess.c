#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("mess");
    set_weight(100000);
    set_value(1);
    set_light(10);
}

init() {
  ::init();
  if(tp->is_player()) {
    present("soul",tp)->set_mout("leaves");
    present("soul",tp)->set_min("arrives");
  return 1;}
}
