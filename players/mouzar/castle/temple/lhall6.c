inherit "room/room";
#include "/players/mouzar/misc/roomt.h"   
string open;
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Corridor of Elementals";
  long_desc="This is a very long corridor.  It looks as though it has no end.\n"+
            "You get the feeling that you are not alone.\n";
  dest_dir=({"players/mouzar/quest/lhall5","north",});
 }
}
init(){
  ::init();
     add_action("south","south");
     add_action("open","open");
}

open(str) {
    notify_fail("open what?\n");
    if (!str)
        return 0;
    if (str == "door") {
    write("The door opens without a sound.\n");
    say(RN + " open the door slowly.\n");
    open="yes";
   return 1;
   }
    return 1;
}
south() {
  if(open == "yes"){
    write("The door closes behind you!\n\n");
    ME->move_player("south#/players/mouzar/quest/droom2");
    say("The door closes behind "+RN+"!\n");
    open == "no";
    return 1;
  }
  write("You run into the door!    OUCH!!\n");
  say(RN +" walks into a door!\n");
  return 1;
}
