#include "room.h"

object army,ob,ob1;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();
int U;  /*  variable to keep track of locked locker  */
int P;   /*  headquarters pass   */

    extra_reset() {
U = 0;  /*  locker locked  */
P = 1;  /*  there is a pass  */
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/hawkeye.c");
      transfer(army, this_object());
ob = clone_object("players/hawkeye/weapons/weapon.c");
move_object(ob, army);
ob1 = clone_object("players/hawkeye/items/good.c");
move_object(ob1, army);
}
    }
ONE_EXIT("players/hawkeye/room/rd3.c", "west",
       "M*A*S*H Swamp",
     "As you enter you see dirty clothes and trash\n"+
     "thrown all about. You notice the beds are not\n"+
     "made and a large gin still catches your eye.\n"+
     "Three foot lockers with U.S Army are next to all of \n"+
     "the beds but they appear to be locked. The man who\n"+
     "stands before you looks as though he was sleeping \n"+
     "before you entered. I dont think you shouldve woken him!\n",1)

init() {
  ::init();
  add_action("search","search");
  add_action("unlock","unlock");
  add_action("open","open");
}

search() {
if(present("hawkeye")) {
  write("Hawkeye says, 'Get the hell out of my stuff!\n"); return 1; }
else {
  write("You search through the clothes and trash and find nothing special.\n");
  return 1; }
}

unlock(str) {
object ob;
if(present("hawkeye")) {
  write("Hawkeye rolls off the bed and SLAPS your hand away from the\n"+
	"locker.  He demands, 'What do you think you're doing?  GET\n"+
	"OUT OF HERE!\n");
  return 1; }
if(!str) { write("Unlock what?\n"); return 1; }

if(str == "locker") {
  if(!present("mash key",this_player())) {
    write("You do not have the means to unlock the locker.\n");
    return 1; }
  if(present("mash key",this_player()) && U == 1) {
    write("The locker is already unlocked.\n");
    return 1; }
  else {
    ob = present("mash key",this_player());
    write("You insert the small key and hear a 'click'.\n");
    U = 1;
    destruct(ob);
    return 1; }
return 1; }
}

open(str) {
if(present("hawkeye")) {
  write("Hawkeye puts his foot against the small of your back and\n"+
	"gives you a shove, sending you ass over tea kettle..\n");
  this_player()->heal_self(-random(40));
  return 1; }
if(!str) { write("Open what?\n"); return 1; }
if(str == "locker") {
  if(U == 0) {
    write("The locker is locked.\n"); return 1; }
  if(U == 1 && P == 1) {
    write("You open the narrow locker and a piece of paper falls out.\n");
    move_object(clone_object("players/hawkeye/quest/hqpass.c"),
      environment(this_player()));
    P = 0;
    return 1; }
  else {
    write("You open the narrow locker and find it empty.\n");
    return 1; }
return 1; }
}
