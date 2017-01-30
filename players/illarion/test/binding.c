#include "/players/jaraxle/ansi.h"
object target;
int time;

web_person(object ob) {
  if(!ob) return;
  target = ob;
  if(shadow(target, 1));
    return 1;
}
  
webbed(){ return 1; }

stop_con_shadow() {
  set_heart_beat(0);
  destruct(this_object());
  return 1;
}

set_time(int x){ 
  set_heart_beat(1);
  time = x; 
}

void struggle() {
  object r;
  if(target && (r=environment(target)))
     tell_room(r,
     target->query_name()+" struggles to break free of the binding!\n");
}

end() {
  object r;
  if(target && (r=environment(target))) {
	  tell_room(r,
    ""+HIR+target->query_name()+" disbelieves and is free!"+NORM+"\n");
    stop_con_shadow();
    return 1; 
  }
  return; 
}

heart_beat() {
  if(!target)
    stop_con_shadow();
  time --;
  if(!random(10)) { 
    struggle();
  }
  if(time < 1) {
    end();
  } 
}

move_player(){
  struggle();
}

move_object(){
  struggle();
}
run_away(){
  struggle();
}
movement(){
  struggle();
}

short() {
  string s;
  if((s=target->short()))
    return s+" "+HIB+"["+HIW+" Spectral Binding "+HIB+"]"+NORM; 
}
