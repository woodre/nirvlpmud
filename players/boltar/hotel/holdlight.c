#include "std_old.h"
int running;

TWO_EXIT("players/boltar/fredroom.c", "north",
 "players/boltar/level2room3.c", "east",
	   "unfin",
 "This area is unfinished as yet, please exuse the dust.\n", 1)

lights(arg) {
set_light(arg);
set_light(1);
return 1;
}
fetch_items() {
  object ob,next;
  int flag;
  if(running) return;
  running = 1;
  ob = first_inventory(this_object());
  while (ob) {
    flag = 0;
    if(!ob->id("hotelroom")) {
      next=next_inventory(ob);
      flag = 1;
      move_object(ob,"/players/boltar/hotel/lostandfound");
    }
    if(flag)
    ob = next;
    if(!flag) ob = next_inventory(ob);
  }
  running = 0;
  return 1;
}
clear() { running = 0; }

