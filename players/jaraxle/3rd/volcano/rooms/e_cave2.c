inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if(arg) return;
  get_random_short();
  get_random_long();
  dest_dir = ({
  "/players/jaraxle/3rd/volcano/rooms/e_cave3","forward",
  "/players/jaraxle/3rd/volcano/rooms/e_cave","back",
  });
set_light(0);
}

