/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
#include "/players/snow/dervish/trials/trial1/rms/jibboobase.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = YEL+"Desert of Jibboo"+NORM;
  create_random_room();
  no_exit_display = 1;
  add_exit(ROOT+"rms/jibboo19.c","north");
  add_exit(ROOT+"rms/jibboo18.c","northeast");
  add_exit(ROOT+"rms/jibboo12.c","east");
  add_exit(ROOT+"rms/jibboo03.c","southeast");
  add_exit(ROOT+"rms/jibboo02.c","south");
  add_exit(ROOT+"rms/jibboo09.c","southwest");
  add_exit(ROOT+"rms/jibboo10.c","west");
  add_exit(ROOT+"rms/jibboo20.c","northwest");
}

short() { return YEL+"Desert of Jibboo"+NORM ; }

init() {
  ::init();
  add_action("check_random_move", "north");
  add_action("check_random_move", "northeast");
  add_action("check_random_move", "east");
  add_action("check_random_move", "southeast");
  add_action("check_random_move", "south");
  add_action("check_random_move", "southwest");
  add_action("check_random_move", "west");
  add_action("check_random_move", "northwest");
}
