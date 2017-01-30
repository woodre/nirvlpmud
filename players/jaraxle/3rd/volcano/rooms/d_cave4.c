inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if (!present("creature") && !present("demon"))
    get_random_mob();
  if(arg) return;
  get_random_short();
  get_random_long();
  dest_dir = ({
  "/players/jaraxle/3rd/volcano/rooms/d_cave5","forward",
 "/players/jaraxle/3rd/volcano/rooms/random_cave5","up",
 "/players/jaraxle/3rd/volcano/rooms/random_cave5","down",
  "/players/jaraxle/3rd/volcano/rooms/d_cave3","back",
  });
set_light(0);
}
