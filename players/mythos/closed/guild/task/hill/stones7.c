#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = RED+"PORTAL"+NORM;
    long_desc =
    RED+"You step into a place of red mist....\n"+NORM;
    
  dest_dir = ({
    "/players/mythos/closed/guild/task/hill/drag.c","back",
  });
} }

realm() { return "NT"; }

init() {
  ::init();
  if(!present("spear",this_object())) {
    tell_room(this_object(),HIR+"\n\t\tFIRE FLARES AND BURNS!\n\n"+NORM);
    tp->zap_object(tp);
  return 1;}
}
