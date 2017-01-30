#include "std.h"
init() {
   if(set_light(0)==0)
     set_light(1);
   add_action("down","down");
}

short() { return "Boltar's village office"; }
id(str) {
   return str =="stairs" || str == "desk";
}
long(str) {
  if(str=="stairs") 
    write("A set of wooden stairs leading down to the pub.\n");
  if(str=="desk") {
    write("A large wood desk with a Nextstation color turbo upon it.\n");
    write("The computer is actually bolted to the desk.\n");
}
  if(str) return 0;
  write("You climb the stairs up to Boltar's village office. It is\n"+
        "rather plain with a wood floor and large windows allowing the\n"+
        "sunlight in. There is a large desk on the far side of the room\n"+
        "and some simple wooden chairs. It's as if the room is designed\n"+
        "to have nothing to steal.\n");
    write("The only exit is down the stairs.\n");
   }
down() {
    call_other(this_player(), "move_player", "down#room/pub3.c");
    return 1;
  }
