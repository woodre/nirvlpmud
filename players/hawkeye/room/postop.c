#include "room.h"

object army,ob;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/hawkeye.c");
      transfer(army, this_object());
ob = clone_object("players/hawkeye/weapons/weapon.c");
move_object(ob, army);
}
    }
 /*bed(str) {
 write("You see a lump in one of the beds and it appears as though\n"+
   "you could pull the sheets\n");
}*/
ONE_EXIT("players/hawkeye/room/rd3.c", "west",
       "M*A*S*H Swamp",
     "As you enter you see dirty clothes and trash\n"+
     "thrown all about. You notice the beds are not\n"+
     "made and a large gin still catches your eye.\n"+
     "Three foot lockers with U.S Army are next to all of \n"+
     "the beds but they appear to be locked. The man who\n"+
     "stands before you looks as though he was sleeping \n"+
     "before you entered. I dont think you shouldve woken him!\n",1)