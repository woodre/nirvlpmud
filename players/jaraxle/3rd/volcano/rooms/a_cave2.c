inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if(arg) return;
  get_random_short();
  get_random_long();
  dest_dir = ({
    "/players/jaraxle/3rd/volcano/rooms/a_cave3","forward",
    "/players/jaraxle/3rd/volcano/rooms/a_cave","back",
    "/players/jaraxle/3rd/volcano/rooms/random_cave","up",
    "/players/jaraxle/3rd/volcano/rooms/random_cave2","northeast",
  });
  set_light(0);
}

