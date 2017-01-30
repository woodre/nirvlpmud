#include "/players/pestilence/ansi.h"
object target;
int time;

web_person(object ob) {
  if(!ob) return;
  target = ob;
  shadow(target, 1);
  return 1; }
  
webbed(){ return 1; }

set_time(int x){ time = x; }

reset() {
  set_heart_beat(1); }

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
  ""+target->query_name()+" struggles to break free of the grasp!\n");
  }
move_object(){
   tell_room(environment(target),
  ""+target->query_name()+" struggles to break free of the grasp!\n");
  }
run_away(){
   tell_room(environment(target),
  ""+target->query_name()+" struggles to break free of the grasp!\n");
  }
movement(){
   tell_room(environment(target),
  ""+target->query_name()+" struggles to break free of the grasp!\n");
  }

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    ""+target->query_name()+" struggles to break free of the grasp!\n");
  return 1; }
  return; }
  
  int query_block_attack(){
  return 1;
}


short() {
  return HIK+"Demon"+NORM+" hands reaching from the ground, hold "+target->short()+" motionless";
}

end() {
  if(target && environment(target)) {
        tell_room(environment(target),
     ""+HIR+target->query_name()+" manages to break free from the Demon's grasp!"+NORM+"\n");
    shadow(target, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}
