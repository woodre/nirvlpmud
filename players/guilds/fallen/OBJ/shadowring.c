#include "../all.h"

object target;
int time;

shadowring(object ob) {
  if(!ob) return;
  target = ob;
  shadow(target, 1);
  return 1; }
  
ringed(){ return 1; }

set_time(int x){ time = x; }

reset() {
  set_heart_beat(1); }

heart_beat() {
  time --;
  if(random(100) < 18){ 
     effect();
      }
  if(time < 1){
  end();
  shadow(target, 0);
  destruct(this_object()); } 
   }
stop_con_shadow() {
  shadow(target, 0);
  destruct(this_object());
  return 1; }
move_player(){
   tell_room(environment(target),
  target->QN+" is caught in a web of shadows.\n");
  target->heal_self(-1);
  }

move_object(){
     tell_room(environment(target),
  target->QN+" is caught in a web of shadows.\n");
  target->heal_self(-1);
  }
  
short() {
  return target->short()+" "+BOLD+BLK+"]"+HIW+"Trapped"+BOLD+BLK+"["+NORM; 
}

run_away(){
   tell_room(environment(target),
    target->query_name()+" struggles in vain against the shadowy bonds of the web!\n");
}

flee(){
  tell_room(environment(target),
    target->query_name()+" struggles in vain against the shadowy bonds of the web!\n");
}

movement(){
   tell_room(environment(target),
    target->query_name()+" struggles in vain against the shadowy bonds of the web!\n");
}

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    target->query_name()+" struggles in vain against the shadowy bonds of the web!\n");
  return 1; }
  return; }

end() {
  if(target && environment(target)) {
	tell_room(environment(target),
      target->query_name()+" breaks free of the web of shadows.\n");
    shadow(target, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}
