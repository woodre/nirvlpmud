inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if (!present("creature") && !present("demon"))
    get_random_mob();
  if(arg) return;
  short_desc = "A cave";
  get_random_long();
  dest_dir = ({
 "/players/jaraxle/3rd/volcano/rooms/a_cave6","back",
 "/players/jaraxle/3rd/volcano/rooms/random_cave2","up",
 "/players/jaraxle/3rd/volcano/rooms/random_cave4","down",
 "/players/jaraxle/3rd/volcano/rooms/random_cave6","north",
  });
set_light(0);
}

