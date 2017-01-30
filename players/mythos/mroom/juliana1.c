#include "/players/mythos/closed/ansi.h"
#define tp this_player()
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle3.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Juliana's Tokyo- Front>> ";
    long_desc =
    RED+"                 JULIANA'S TOKYO- FRONT\n\n"+NORM+
        "You step into the front hall of Juliana's Tokyo.  Two big buff\n"+
        "bouncerslook over you carefully <If you are a criminal dont even\n"+
        "try to get in>.  Music booms from the dance floor and lights flash\n"+
        "as lasers are spun....\n";
  items = ({
    "DJ","Head to the DJ consol",
    "out","Leave Juliana's",
    "floor","Head toward the dance floor",
  });

  dest_dir = ({
  "/players/mythos/mroom/juliana.c","out",
  "/players/mythos/mroom/juliana2.c","DJ",
  "/players/mythos/mroom/juliana3.c","floor",
  });
} }

init() {
  ::init();
  if(tp->query_crime()) {
  write("\tYou are a criminal!\nA bouncer tosses you out.\n");
  say("\tA bouncer tosses "+capitalize(tp->query_real_name())+" out!\n");
  move_object(clone_object("/players/mythos/mmisc/snipe.c"),tp);
  move_object(tp,"/players/mythos/mroom/juliana.c");
  }
}
