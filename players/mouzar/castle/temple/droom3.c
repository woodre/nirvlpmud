inherit "room/room";
#include "/players/mouzar/misc/roomt.h"   
string sopen, open;
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Wyrm-Priest's Work Chambers";
  long_desc="This is where the priests keep the records of what supplies they have\n"+
            "or don't have.  This is a simple room with nothing on the walls. Theren"+ 
            "is a over hanging lamp to light the room for the priest who works here\n"+
            "to see what he was seeing.  You can only see one door leading to the north.\n";
  dest_dir=({"players/mouzar/quest/droom6","south",
             "players/mouzar/quest/droom2","east",});
 }
 if(!present("priest",this_object())){
   move_object(clone_object("/players/mouzar/quest/mon/ppriest"),this_object());
 }
}
init(){
  ::init();
     add_action("north","north");
     add_action("push","push");
     add_action("look","look");
}

push(str) {
    notify_fail("push what?\n");
    if (!str)
        return 0;
    if (str == "wall") {
    write("You the out-line and it swings open.\n");
    say(RN + " pushs the west wall opening up a secret passage.\n");
    sopen="yes";
    return 1;
   }
    return 1;
}
north() {
  if(sopen == "yes"){
    write("The wall closes behind you!\n\n");
    ME->move_player("north#/players/mouzar/quest/hhall6");
    say("The wall closes behind "+RN+"!\n");
    sopen == "no";
    return 1;
  }
  write("You walk into a wall!    OUCH!!\n");
  say(RN +" walks into a wall!\n");
  return 1;
}
look(str) {
  if(sscan(str, %s %s, boo, bing) != 2) return 0;
  if(boo == "west" && bing == "wall") {
    write("You notice the out-line of a door in the wall.\n");
    return 1;
  }
}
