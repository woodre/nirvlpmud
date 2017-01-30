#include <ansi.h>
object bastard;
int time;

dart_loser(object ob) {
  if(!ob) return;
  bastard = ob;
  shadow(bastard, 1);
  return 1; }
  
tranqed(){ return 1; }

set_time(int x){ time = x; }

reset() {
  set_heart_beat(1); }

heart_beat() {
  time --;
  if(random(100) < 25){ 
    screwed();
      }
  if(time < 1){
  crapped();
     } 
   }
stop_con_shadow() {
  shadow(bastard, 0);
  destruct(this_object());
  return 1; }
move_player(){
  tell_room(environment(bastard),
  bastard->query_name()+" stumbles around in a drugged stuper!\n");
  }
move_object(){
  tell_room(environment(bastard),
  bastard->query_name()+" stumbles around in a drugged stuper!\n");
  }
run_away(){
  tell_room(environment(bastard),
  bastard->query_name()+" tries to run but falls down in a drugged stuper!\n");
  }
movement(){
  tell_room(environment(bastard),
  bastard->query_name()+" tries to run but falls down in a drugged stuper!\n");
  }

screwed() {
  if(bastard && environment(bastard)) {
  tell_room(environment(bastard),
    bastard->query_name()+" stumbles around in a drugged stuper!\n");
  return 1; }
  return; }

short() {
  return bastard->short()+" "+BOLD+"~~"+CYN+"StOnEd"+NORM+BOLD+"~~"+NORM+" "; 
}

crapped() {
  if(bastard && environment(bastard)) {
    tell_room(environment(bastard),
    ""+BOLD+bastard->query_name()+" regains their focus again as the drugs wear off."+NORM+"\n");
    shadow(bastard, 0);
    destruct(this_object()); 
  return 1; 
  }
  return; 
}
