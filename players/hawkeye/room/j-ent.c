

#include "std.h"
id(str) {return str == "tree";}
reset(arg){
    if(!arg){
    set_light(1);
    }
}
 init()
 {
    add_action("exit_rambo","climb");
    add_action("exit_east", "east");
   add_action("exit_west", "west");
 }

 short() {
   return "A Jungle";
 }
long(str){
  write("You are in an intense Jungle, How you got here you dont know\n" +
    "but you feel as if someone or something is watching you.\n" +
  "You see the jungle get more intese to the west and\n" +
   "the M*A*S*H camp is back east.\n" +
"A large tree is within sight.\n");
}

  exit_rambo(str) {
  if(!id(str)) {
  return 0;
}
else {
 call_other(this_player(),"move_player","tree#players/hawkeye/room/rambo.c");
    return 1;
}
 }

exit_east(){
    call_other(this_player(),"move_player","east#players/hawkeye/room/lat.c");

    return 1;
}

 exit_west() {
  call_other(this_player(), "move_player", "west#players/hawkeye/room/d-room.c");
  return 1;
}
