#include "/players/maledicta/ansi.h"
object target;
int time;

web_person(object ob) {
  if(!ob) return;
  target = ob;
  shadow(target, 1);
  return 1; }
  
pummeled(){ return 1; }

set_time(int x){ time = x; }

reset(arg){
  set_heart_beat(1); }


id(str){ return str == "wind_stun"; }
heart_beat() {
  time --;
  if(random(100) < 25){ 
     effect();
      }
  if(time < 1){
  end();
     } 
   }
stop_con_shadow() {
  shadow(target, 0);
  destruct(this_object());
  return 1; }
move_player(){
   tell_room(environment(target),
  target->query_name()+" looks "+HIC+"stunned"+NORM+".\n");
  }
move_object(){
   tell_room(environment(target),
  target->query_name()+" looks "+HIC+"stunned"+NORM+".\n");
  }
run_away(){
   tell_room(environment(target),
  target->query_name()+" looks "+HIC+"stunned"+NORM+".\n");
  }
movement(){
   tell_room(environment(target),
  target->query_name()+" looks "+HIC+"stunned"+NORM+".\n");
  }

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    target->query_name()+" looks "+HIC+"stunned"+NORM+".\n");
  return 1; }
}

short() {
return target->short()+"  "+HIB+"("+HIC+"*"+HIW+"stunned"+HIC+"*"+NORM+HIB+")"+NORM;
}

end() {
  if(target && environment(target)) {
	tell_room(environment(target),
""+BLU+target->query_name()+" shakes off the stun.\n"+NORM);
    shadow(target, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}

