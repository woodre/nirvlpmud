#include "/players/wocket/closed/ansi.h"
object quick;
quickshad_on(){
shadow(quick,1);
}

quickshad_off(){
  shadow(quick,0);
  destruct(this_object());
  return 1;
}

attack(){
  tell_room(environment(quick),quick->query_name()+" puts down its weapon and begins to cry.\n");
}

query_rescued(){ return 1; }
short(){
  return "a nonge";
}
attacked_by(ob){
  tell_room(environment(quick),"Attacked by function called.\n");
}

set_monster(mon){
  if(!mon) return 0;
  quick = mon;
quickshad_on();
  return 1;
}
