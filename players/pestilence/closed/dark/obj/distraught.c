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
  ""+target->query_name()+" tries to break the "+HIR+"chains"+NORM+"!\n");
  }
move_object(){
   tell_room(environment(target),
  ""+target->query_name()+" tries to break the "+HIR+"chains"+NORM+"!\n");;
  }
run_away(){
   tell_room(environment(target),
 ""+target->query_name()+" tries to break the "+HIR+"chains"+NORM+"!\n");
  }
movement(){
   tell_room(environment(target),
 ""+target->query_name()+" tries to break the "+HIR+"chain"+NORM+"s!\n");
  }

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    ""+target->query_name()+" tries to break the "+HIR+"chains"+NORM+"!\n");
  return 1; }
  return; }

short() {
  return target->short()+" is "+HIR+"maniacally chained"+NORM+" to the ground"; 
}

end() {
  if(target && environment(target)) {
        tell_room(environment(target),
     ""+HIR+target->query_name()+" manages to break free from the chains of madness."+NORM+"\n");
    shadow(target, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}
