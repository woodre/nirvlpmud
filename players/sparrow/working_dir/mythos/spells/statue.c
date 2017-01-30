#include "/players/mythos/closed/guild/def.h"
string msg, msg_l, stat_trap;
int tim;
id(str) { return str == "stasis" || str == stat_trap;}

reset(arg) {
  if(arg) return;
  call_out("vanish",10);
}

short(){return msg;}
long() {return msg_l;}

drop() {return 1;}
get() { return 1;}
set_short(str) { msg = str;}
set_time(n) { tim = n;}
set_trap(str) { stat_trap = str; }

init() {
  add_action("stuck"); add_xverb("");
}

stuck() {
  if(tpn == stat_trap) {
  write("You are in temporal stasis!\n");
  return 1;}
}

vanish() {
if(!environment(this_object())) { return 1; }
if(tim < 1) { 
move_object(present(stat_trap,this_object()),environment(this_object()));
tell_room(environment(this_object()),capitalize(stat_trap)+" is free!\n");
destruct(this_object());
return 1;}
tim = tim - 2;
call_out("vanish",10);
return 1;}

query_shatter_proof() { return 1;}
