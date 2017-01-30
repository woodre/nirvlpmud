/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
#include "/players/snow/dervish/trials/trial1/rms/jibboobase-rocky.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

reset(arg) {
  if(arg) return;
  short_desc = YEL+"Desert of Jibboo"+NORM;
  create_random_room();
  add_item("rock",
    "A large gnarled by heavy winds and scouring sands");
  add_item("rocks",
    "Several of the rocks are arranged in a pattern pointing northward");
  no_exit_display = 1;
  add_exit(ROOT+"rms/jibboo09.c","north");
  add_exit(ROOT+"rms/jibboo02.c","northeast");  
  add_exit(ROOT+"rms/jibboo01.c","east");
  add_exit(ROOT+"rms/jibboo06.c","southeast");
  add_exit(ROOT+"rms/jibboo07.c","south");
  add_exit(ROOT+"rms/jibboo22.c","southwest");
  add_exit(ROOT+"rms/jibboo23.c","west");
  add_exit(ROOT+"rms/jibboo24.c","northwest");
}

short() { return YEL+"Desert of Jibboo"+NORM ; }

init() {
  ::init();
  add_action("check_random_move", "northeast");
  add_action("check_random_move", "east");
  add_action("check_random_move", "southeast");
  add_action("check_random_move", "south");
  add_action("check_random_move", "southwest");
  add_action("check_random_move", "west");
  add_action("check_random_move", "northwest");
}


