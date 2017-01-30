#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-2);
    short_desc = "DARKNESS";
    long_desc =
    "\n";
  items = ({
    "north","Darkness....",
    "east","Darkness....",
    "south","Darkness....",
    "west","Darkness....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/cave.c", "out",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    if(!pp) { 
       tell_object(tp,"Something flashes and you are thrown out of the caves!\n");
        tp->heal_self(-30);
        move_object(tp,"/players/mythos/closed/guild/forest/rooms/cave.c");}
}
