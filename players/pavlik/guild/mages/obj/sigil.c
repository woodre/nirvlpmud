inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define ROOM environment(this_object())

/*
 * See the file /players/pavlik/mages/spells/sigil for
 * details on this objects function.
 */

object sigil, badguy;
string owner;
reset(arg){
::reset(arg);
if(arg) return;
 set_name("Fire Elemental");
 set_race("sigil");
 set_short("Fire Elemental");
 set_long("Fire Elemental.\n");
 set_hp(200);
 set_wc(18);
 set_ac(3);
 set_level(1);
 owner = "noone";
 sigil = 0;
 badguy = 0;
 call_out("sigil_check", 3);
}

short(){
  if(!sigil) return 0;
  return "A Fire Elemental [guarding "+capitalize(sigil->query_name())+"]";
}

long(){
  if(!sigil) return;
  write(
  "A blazing inferno of nastiness stands here.  The angry Fire\n"+
  "elemental stands protectively in front of "+
  capitalize(sigil->query_name())+"\n"+
  "The efreet looks at you and snarls.\n");
  return;
}

id(str){ return str == "elemental" || str == "sigil" || 
   str == owner+"'s sigil";
}

set_sigil(str){ sigil = str; }
query_sigil(){ return sigil; }
set_owner(str){ owner = str; }
query_owner(){ return owner; }
query_badguy(){ return badguy; }

sigil_check(){
  string name;

  if(!find_player(owner)){
    dismiss_sigil();
    return 1;
  }

  if(!sigil){
    tell_object(find_player(owner),
    HIR+"[Sigil]: Your Sigiled monster is gone.\n"+NORM+
    "Your sigil disappears.\n");
    dismiss_sigil();
    return 1;
  }

  name = capitalize(sigil->query_name());

  /* no attacker or attacker is owner */
  if((!sigil->query_attack()) || (sigil->query_attack() == find_player(owner))) {
    call_out("sigil_check", 3);
    return 1;
  }

  /* is attacker the owner's pet? */
  if(sigil->query_attack()->query_owner() == owner){
    call_out("sigil_check", 3);
    return 1;
  }

  /* has this person already been warned once? */
  if(sigil->query_attack() == badguy){
    tell_room(ROOM,
    "Fire Elemental booms: "+HIR+"I WARNED YOU!\n"+NORM+
    "Fire Elemental jumps into the battle!\n");
    tell_object(find_player(owner),
    HIR+"[Sigil]"+NORM+": "+HIC+capitalize(badguy->query_name())+NORM+
    " is attacking your sigiled target!\n");
    this_object()->attack_object(sigil->query_attack());
    call_out("sigil_check2", 10);
    return 1;
  } else {
    tell_room(ROOM,
    HIR+"Fire Elemental stops all fighting.\n"+NORM+
    "Fire Elemental says: This is "+capitalize(owner)+"'s kill.\n"+
    "Fire Elemental says: Please do not interfere.\n");
    badguy = sigil->query_attack();
    do_peace();
    call_out("sigil_check", 3);
    return 1;
  }
  call_out("sigil_check", 3);
  return 1;
}

/*
 * sigil_check2 will reset the badguy variable if noone
 * else attacks the target.
 */
sigil_check2(){
  if(!present(sigil, environment(this_object()))){
    sigil_check();
    return;
  }

  if(!find_player(owner)){
    dismiss_sigil();
    return 1;
  }

  if(!sigil->query_attack()){
    badguy = 0;
    call_out("sigil_check", 3);
    return 1;
  }

  if(sigil->query_attack() != badguy) {
    badguy = 0;
    call_out("sigil_check", 1);
    return 1;
  }

  call_out("sigil_check2", 3);
  return 1;
}

do_peace(){
  object obj;
  obj = first_inventory(environment(this_object()));
  while(obj){
    object cur;
    cur = obj;
    obj = next_inventory(obj);
    cur->stop_fight(); cur->stop_hunter();
    cur->stop_fight(); cur->stop_hunter();
  }
  return 1;
}

dismiss_sigil() {
  tell_room(environment(this_object()),
  "A Fire Elemental cracks open the Earth and jumps inside.\n"+
  "The elemental disappears.\n");
  destruct(this_object());
  return 1;
}

