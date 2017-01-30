#include "/players/feldegast/defines.h"

string dest;

id(str) {
  return str=="portal" || str=="azure portal";
}

short() {
  return "An "+BLU+"azure"+NORM+" portal";
}

long() {
  write(
"This is a pulsing rectangle of azure light standing\n"+
"perpendicular to the ground, half a dozen paces wide\n"+
"and half again the height of a grown man.  You could\n"+
"enter it if you chose.\n");
}

drop() { return 0; }

query_destination(str) {
  return dest;
}

set_destination(str) {
  dest=str;
}

init() {
  add_action("cmd_enter","enter");
}

cmd_enter(str) {
  notify_fail("Enter what?\n");
  if(!str) return 0;
  if(str!="portal" && str!="azure portal") return 0;
  say(TPN+" steps into the "+BLU+"azure"+NORM+" portal.\n");
  write("You step through the "+BLU+"azure"+NORM+" portal.\n");
  move_object(this_player(),dest);
  say(TPN+" steps into the room through an "+BLU+"azure"+NORM+" portal.\n");
  command("look",this_player());
  return 1;
}
