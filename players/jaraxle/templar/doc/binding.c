#include "/players/maledicta/ansi.h"
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
  target->query_name()+" struggles to break free of the webbing!\n");
  }
move_object(){
   tell_room(environment(target),
  target->query_name()+" struggles to break free of the webbing!\n");
  }
run_away(){
   tell_room(environment(target),
  target->query_name()+" struggles to break free of the webbing!\n");
  }
movement(){
   tell_room(environment(target),
  target->query_name()+" struggles to break free of the webbing!\n");
  }

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    target->query_name()+" struggles to break free of the webbing!\n");
  return 1; }
  return; }

short() {
  return target->short()+" "+BOLD+" .xX WEBBED Xx."+NORM; 
}

end() {
  if(target && environment(target)) {
	tell_room(environment(target),
     ""+HIR+target->query_name()+" manages to free themself from the webbing."+NORM+"\n");
    shadow(target, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}

