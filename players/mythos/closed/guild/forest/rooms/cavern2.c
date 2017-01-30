#include "/players/mythos/closed/guild/def.h"
#include "/sys/ansi.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-1);
    short_desc = HIK+"DARKNESS"+NORM;
    long_desc =
    "\n";
  items = ({
    "out","The exit....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/cavern.c", "out",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    if(!pp) { 
       tell_object(tp,"Something flashes and you are thrown out of the cavern!\n");
        tp->heal_self(-30);
        move_object(tp,"/players/mythos/closed/guild/forest/rooms/cavern.c");}
}
