#include "room.h"

int P;
object army,ob,ob1;
realm() {return "NT";}
#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
P = 1;
  if(!army || (present("army"))) {
army = clone_object("players/hawkeye/monster/supply1.c");
      transfer(army, this_object());
/*
ob1 = clone_object("players/hawkeye/quest/cpipe.c");
move_object(ob1, army);
*/
}
    }
ONE_EXIT("players/hawkeye/room/hq1.c", "east",
     "Supply Room",
 "Do you really want to wait in line?....What should you do?.\n",1)

init() {
  ::init();
  add_action("search","search");
}

search() {
if(present("supply")) {
  write("The supply sergeant says, 'I think you'd best be moving on, sir!\n");
  return 1; }
if(P == 1) {
  write("You search the dusty shelves and find something.\n");
  move_object(clone_object("players/hawkeye/quest/cpipe.c"),
    this_player());
  P = 0;
  return 1; }
else {
  write("You search the dusty shelves and find nothing.\n");
  return 1; }
}
