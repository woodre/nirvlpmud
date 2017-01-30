/*  10/06/2006 - Rumplemintz
      removed trailing ; in include statement
*/

inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if (!present("npc") && !present("demon"))
    get_random_mob();

  if(arg) return;
  get_random_short();
  get_random_long();
  dest_dir = ({
    "/players/jaraxle/3rd/volcano/rooms/a_cave2","forward",
    "/players/jaraxle/3rd/volcano/rooms/trail2","out",
  });
  set_light(0);
}

