inherit "room/room";
#include "/players/mouzar/misc/roomt.h"   
string open;
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Living Chamber";
  long_desc="This is a general resting and eating room where the guards and clerics\n"+
            "meet and relax while off-duty.  It has the basic stuff.  Better hope\n"+
            "that the guards are all on duty, cause they wouldn't be happy to see\n"+
            "here.  They wouldn't like to take their work to their resting area.\n"+
            "There is a door to the north.";
  dest_dir=({"players/mouzar/quest/lroom5","south",
             "players/mouzar/quest/lroom2","east",});
 }
}
init(){
  ::init();
     add_action("north","north");
     add_action("open","open");
}

open(str) {
    notify_fail("open what?\n");
    if (!str)
        return 0;
    if (str == "door") {
    write("The door opens with a squeak.\n");
    say(RN + " open the door slowly.\n");
    open="yes";
   return 1;
   }
    return 1;
}
north() {
  if(open == "yes"){
    write("The door closes behind you!\n\n");
    ME->move_player("north#/players/mouzar/quest/groom8");
    say("The door closes behind "+RN+"!\n");
    open == "no";
    return 1;
  }
  write("You run into the door!    OUCH!!\n");
  say(RN +" walks into a door!\n");
  return 1;
}
