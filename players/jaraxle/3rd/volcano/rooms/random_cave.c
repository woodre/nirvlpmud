inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/3rd/volcano/rooms/room_desc.h"

object ob;
reset(arg){
  if (!present("creature") && !present("demon"))
    get_random_mob();
  if(arg) return;
  get_random_short();
  get_random_long();
  get_random_exit();
set_light(0);
if(!find_living("jaraxle_big_fucking_monster")) { ob = clone_object("/players/jaraxle/3rd/volcano/mons/fire"); move_object(ob, this_object()); ob->move();
}
}
 init(){ ::init(); write("You wander through the caves.\nSuddenly you have lost your berrings.\n"); }
