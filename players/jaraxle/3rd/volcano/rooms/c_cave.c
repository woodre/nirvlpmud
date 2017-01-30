inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if (!present("creature") && !present("demon"))
    get_random_mob();
  if(arg) return;
  get_random_short();
  get_random_long();
  dest_dir = ({
  "/players/jaraxle/3rd/volcano/rooms/c_cave2","forward",
 "/players/jaraxle/3rd/volcano/rooms/random_cave3","north",
  "/players/jaraxle/3rd/volcano/rooms/trail4","out",
  });
set_light(0);
}

