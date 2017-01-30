/* this is the overheat object, it stops all    */
/* actions from the pilot, except to bail out   */
#include "DEFS.h"

id(str) { return OVERHEAT_ID; }
get() { return 0; }
drop() { return 1; }
reset() {}


set_cooldown(int time) {
  call_out("all_done", 1, time);
#ifndef __LDMUD
  add_action("stop_actions"); add_xverb("");
#else
  add_action("stop_actions", "", 3);
#endif
  return 1;
}


stop_actions(string str) {
  string mesg;
  if(str) if(str == "bail") { 
     call_other(CMDDIR+"bail.c","main");
     destruct(this_object());
     return 1;
   }
   if(str) if(sscanf(str, "comm%s", mesg)) {
     call_other(CMDDIR+"comm.c","main",mesg);
     return 1;
   }
   if(str) if(str == "sys") { }
   else {
    tell_room(ETO, "Your mech has overheated, you can do nothing.\n");
    tell_room(ETO, "The only thing you can do is to 'bail', 'sys', or 'comm'.\n");
    return 1; }
}

all_done(int time) {
  if(time <= 0) {
    tell_room(ETO, "Cooldown completed, thermal systems regulated.\n");
    tell_room(ETO, "Sytems reactivated.\n");
    destruct(this_object());
    return 1; }
  time -= 1;
  call_out("all_done", 1, time);
  return 1;
}

cancel_overheat() {
  remove_call_out("all_done");
  destruct(this_object());
}

