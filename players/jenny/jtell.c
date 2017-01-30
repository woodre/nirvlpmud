/*
This lets players talk to Jenny while they are invisible.
LUCKY THEM!
 */
#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
string str;
object jgirl;
reset(int arg) {
  if(arg) return;
  set_id("jtell");
set_short(BLU+"jtell"+NORM);
set_long(
"You can use this to talk to jenny, even when she is invisible.\n"+
"Just type "+BLU+"jtell message."+NORM+"\n");
set_weight(0);
set_value(0);
set_dest_flag(1);
}
init() {
  ::init();
add_action("jennymessage","jtell");
}
jennymessage(str) {
jgirl = find_player("jenny");
if(!str) {notify_fail("What do you want to say?\n"); return 1;}
if(!jgirl) {write("Jenny is not logged on.\n");
return 1;}
tell_object(jgirl, BOLD+BLU+TPN+" tells you:  "+WHT+str+NORM+"\n");
write(BLU+"You tell Jenny;  "+WHT+str+NORM+"\n");
return 1;}
drop() { return 1; }
give() { return 1; }
