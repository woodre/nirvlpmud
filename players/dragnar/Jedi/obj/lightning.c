#include <ansi.h>

object target;
int time, ac_effect;

set_victim(object ob) {
  if(!ob) return;
  target = ob;
  shadow(target, 1);
  return 1; }
  
is_lightning(){ return 1; }

set_time(int x) {
  time = x;
  ac_effect = target->query_ac();
  if(ac_effect > 14) ac_effect = 14;
}

stop_con_shadow() {
  shadow(target, 0);
  destruct(this_object());
  return 1; }

reset() {
  set_heart_beat(1); }

heart_beat() {
  time --;
  if(random(100) < 25){ 
     effect();
      }
  if(time < 1){
  end();
  shadow(target, 0);
  destruct(this_object()); } 
   }

hit_player(int num) {
  num += random(ac_effect);
  return target->hit_player(num); 
}
    
short() {
  return target->short()+" "+HIB+"[agonized]"+NORM+""; }

effect() {
  if(target && environment(target)) {
  tell_room(environment(target),
    target->query_name()+" falls to the ground in agony as "+HIB+"lightning"+NORM+" dances over "+
    "their\n"+
    "prone form!\n");
  return 1; }
  return; }

end() {
  if(target && environment(target)) {
  tell_room(environment(target),
    target->query_name()+" recovers from the lightning's grasp and climbs to "+
    ""+target->query_possessive()+" feet.\n");
  return 1; }
  return; }
