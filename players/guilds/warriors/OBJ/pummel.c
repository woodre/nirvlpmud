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
  target->query_name()+" stumbles around dazed!\n");
  }
move_object(){
   tell_room(environment(target),
  target->query_name()+" stumbles around dazed!\n");
  }
run_away(){
   tell_room(environment(target),
  target->query_name()+" stumbles around dazed!\n");
  }
movement(){
   tell_room(environment(target),
  target->query_name()+" stumbles around dazed!\n");
  }

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    target->query_name()+" stumbles around dazed!\n");
  return 1; }
  return; }

short() {
  return target->short()+" "+RED+" ("+HIR+"dazed"+NORM+RED+")"+NORM; 
}

end() {
  if(target && environment(target)) {
	tell_room(environment(target),
     ""+HIR+target->query_name()+" recovers from being pummeled."+NORM+"\n");
    shadow(target, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}

