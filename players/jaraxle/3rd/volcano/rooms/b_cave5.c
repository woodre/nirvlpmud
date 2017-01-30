inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if (!present("creature") && !present("demon"))
    get_random_mob();
  if(arg) return;
  short_desc = "A cave";
  get_random_long();
  dest_dir = ({
  "/players/jaraxle/3rd/volcano/rooms/b_cave6","forward",
  "/players/jaraxle/3rd/volcano/rooms/b_cave4","back",
  });
set_light(0);
}

