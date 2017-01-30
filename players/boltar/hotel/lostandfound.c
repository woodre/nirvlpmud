#include "room.h"
int running;

ONE_EXIT("players/boltar/hotel/hotel.c", "west",
 "Lost and Found",
 "This unfinished room is where various lost items from hotel rooms\n"+
 "end up. \n", 1)

init() {
 ::init();
  if(running) return;
  running = 1;
  call_other("/players/boltar/hotel/holddark","fetch_items",0);
  call_other("/players/boltar/hotel/holdlight","fetch_items",0);
  running = 0;
  call_other("/players/boltar/hotel/holddark","clear",0);
  call_other("/players/boltar/hotel/holdlight","clear",0);
  return 1;
}


