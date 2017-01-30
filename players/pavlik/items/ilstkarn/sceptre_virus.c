#include "/players/pavlik/closed/colors.h"
#define IT capitalize(target->query_name())

/*
 * This virus is caused by the Kings Sceptre (~/items/ilstkarn/kings_sceptre).
 * This virus is permanent and will reduce the victims health until
 * it is less than 10%.  Please review the sceptre object for more info
 * in this virus.
 */

object target;

reset(arg){
 if(arg) return;
}

short(){ return; }
long(){ write("the sceptre virus.\n"); return; }
id(str){ return str == "sceptre_virus" || str == "virus"; }
get(){ return 0; }
drop(){ return 1; }
extra_short(){ return "(*virus*)"; }
extra_look(){ return IT+" has been infected with a deadly virus!"; }
set_target(ob){ target = ob; }
query_target(){ return target; }

start_virus(ob) {
  target = ob;
  call_out("virus_check", 5);
  return 1;
}

virus_check() {
  int i;
  int dmg;
  int hp;

  if(!target || environment() != target) {
    destruct(this_object());
    return 1;
  }
  
  i = random(9);

  if(i == 0) tell_room(environment(target),
  IT+" looks sickly and frail.\n");
  else if(i == 2) tell_room(environment(target),
  "A strange green fungus seems to be growing on "+IT+"'s skin.\n");
  else if(i == 4) tell_room(environment(target),
  IT+"'s eyes are rimmed with dark unhealthy circles.\n");
  else if(i == 6) tell_room(environment(target),
  IT+" doubles over and pukes.\n");

  hp = target->query_hp();

  /* Don't do any damage if target is under 10% health */
  if(hp < (target->query_mhp()/10)) {
    call_out("virus_check", 10);
    return 1;
  }

  dmg = 1+random(5);
  if(dmg > hp) dmg = hp;
  target->hit_player(dmg);

  call_out("virus_check", 10);
  return 1;
}
 
