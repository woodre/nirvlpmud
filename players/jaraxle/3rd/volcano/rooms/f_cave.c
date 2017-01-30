inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if(arg) return;
  get_random_short();
  get_random_long();
  dest_dir = ({
  "/players/jaraxle/3rd/volcano/rooms/f_cave2","forward",
  "/players/jaraxle/3rd/volcano/rooms/trail8","out",
  });
set_light(0);
}

