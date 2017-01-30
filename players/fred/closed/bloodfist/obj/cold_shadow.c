#include "/players/zeus/closed/all.h"

object target;
int time;

apply_cold_enchantment(object ob) {
  if(!ob) return;
  target = ob;
  time = 4;
  shadow(target, 1);
  return 1;
}
  
query_cold_enchantment(){ return 1; }
reset(){  set_heart_beat(1); }

heart_beat(){
  time --;
  if(random(100) < 30){
    tell_room(environment(target), target->QN+"'s movements are "+
      "slowed by the ice.\n");
  }
  else if(random(100) < 30){
    tell_room(environment(target), target->QN+" struggles against "+
      "the ice enchantment.\n");
  }
  else if(random(100) < 30){
    tell_room(environment(target), "Fragments of ice fall from "+
      target->QN+" as "+target->query_pronoun()+" moves.\n");
  }
  if(time < 1){
    end();
    shadow(target, 0);
    destruct(this_object()); 
  } 
}

stop_con_shadow() {
  shadow(target, 0);
  destruct(this_object());
  return 1; }

move_player(){  return 1; }
move_object(){  return 1; }
reapply(){     time += 4; }

end() {
  if(target && environment(target)){
	  tell_room(environment(target), "The ice melts from "+
      target->query_name()+"...\n");
    shadow(target, 0);
    destruct(this_object()); 
    return 1; 
  }
  return; 
}
