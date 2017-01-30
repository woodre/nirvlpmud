#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Dome of Shackles ";
    long_desc =
    "Before you is a shimmering field.  The field\n"+
    "seems to surround a pedastal within.\n"+
    "Be sure you have what is needed.\n";
  items = ({
    "enter","Enter beyond the shield...",
    "back","Back to the hills",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hill/hills2.c","back",
    "/players/mythos/closed/guild/task/hill/enter.c","enter",
  });
} }

realm() { return "NT"; }

init() {
 ::init();
 add_action("enter","enter");
}

enter() {
    if(tgl != 8 || tl < 17 || qtf < 10 || !present("taormin",tp)) {
      write("Suddenly you feel that something is seriously wrong!\n");
      if(random(3)==0) tp->zap_object(tp);
    return 1;}
}
