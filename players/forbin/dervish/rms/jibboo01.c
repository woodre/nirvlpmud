/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
#include "/players/snow/dervish/trials/trial1/rms/jibboobase-rocky.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = YEL+"Desert of Jibboo"+NORM;
  create_random_room(); 
  add_item("rock",
    "Strong desert winds have made the rock smooth over time");
  add_item("rocks",
    "Several of the rocks are arranged in a pattern pointing eastward");
  no_exit_display = 1;
  add_exit(ROOT+"rms/jibboo02.c","north");
  add_exit(ROOT+"rms/jibboo03.c","northeast");
  add_exit(ROOT+"rms/jibboo04.c","east");
  add_exit(ROOT+"rms/jibboo05.c","southeast");
  add_exit(ROOT+"rms/jibboo06.c","south");
  add_exit(ROOT+"rms/jibboo07.c","southwest");
  add_exit(ROOT+"rms/jibboo08.c","west");
  add_exit(ROOT+"rms/jibboo09.c","northwest");
}

short() { return YEL+"Desert of Jibboo"+NORM ; }

init() {
  ::init();
  add_action("check_random_move", "north");
  add_action("check_random_move", "northeast");
  add_action("check_random_move", "southeast");
  add_action("check_random_move", "south");
  add_action("check_random_move", "southwest");
  add_action("check_random_move", "west");
  add_action("check_random_move", "northwest");
}

query_where_am_i() { return 6; }