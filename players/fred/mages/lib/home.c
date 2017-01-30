#include "/players/fred/mages/defs.h"

cmd_home() {
 string home;

/* Added to kickout if wizard -- Rumplemintz */
  if (USER->query_level() >= 21)
    return 0;

  home = USER->query_home();
    if(home == "/room/church" || home == 0) {
      write("Home now set to the Black Circle guild hall.\n");
      USER->set_home("/players/fred/mages/rooms/hall.c"); return 1; }
    write("Home now set to the church.\n");
    USER->set_home("/room/church");
    return 1; }
