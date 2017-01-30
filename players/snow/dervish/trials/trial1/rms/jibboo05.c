/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
#include "/players/snow/dervish/trials/trial1/rms/jibboobase.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

reset(arg) {
  if(arg) return;
  short_desc = YEL+"Desert of Jibboo"+NORM;
  create_random_room();
  no_exit_display = 1;
  add_exit(ROOT+"rms/jibboo04.c","north");
  add_exit(ROOT+"rms/jibboo15.c","northeast");
  add_exit(ROOT+"rms/jibboo16.c","east");
  add_exit(ROOT+"rms/jibboo17.c","southeast");
  add_exit(ROOT+"rms/jibboo18.c","south");
  add_exit(ROOT+"rms/jibboo19.c","southwest");
  add_exit(ROOT+"rms/jibboo06.c","west");
  add_exit(ROOT+"rms/jibboo01.c","northwest");
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
