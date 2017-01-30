inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

reset(arg){
  if (!present("creature") && !present("demon"))
    get_random_mob();
  if(arg) return;
  get_random_short();
  get_random_long();
  get_random_exit();
set_light(0);
}

init(){ ::init(); write("You wander through the caves.\nSuddenly you have lost your berrings.\n"); }
