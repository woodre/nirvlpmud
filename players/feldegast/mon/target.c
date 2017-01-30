#include "defs.h"
inherit "/obj/monster";

int woopee;
int tries;
int total;
int max;
int min;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("target");
  set_short("A wooden practice target");
  set_long(
    "This is a simple wooden target used to measure the strength of an\n"+
    "attack.  <renew> to reset its stats.\n"
  );
  set_gender("male");
  set_race("golem");
  set_level(20);
  set_wc(0);
  set_ac(0);
  set_hp(2000);
  set_al(0);
}

init() {
  add_action("renew"); add_verb("renew");
  add_action("gkill"); add_verb("gkill");
  add_action("ac","ac");
}


heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    total+=woopee;
    this_object()->heal_self(woopee);
    tries+=1;
    tell_room(environment(),"DAMAGE: "+woopee+" AVERAGE: "+(total/tries)+" TOTAL: "+total+"\n");
    tell_room(environment(), "MAX: "+max+"\n");
    woopee=0;
  }
}

renew() {
  tries=0;
  total=0;
  write("The target's statistics are renewed.\n");
  return 1;
}

gkill(arg) {
  if(!arg) {
    write("Have the target attack who?\n");
    return 1;
  }
  if(!present(arg)) {
    write(capitalize(arg)+" is not here.");
    return 1;
  }
  attack_object(present(arg));
  write("The practice target shudders to life and attacks"+capitalize(arg)+".\n");
  return 1;
}

ac(arg) {
  int x;
  x=atoi(arg);
  set_ac(x);
  write("Setting ac to "+x+".\n");
  return 1;
}

hit_player(x) {
  tell_room(environment(),HIR+"["+NORM+x+HIR+"]"+NORM);
  woopee+=x;
  if(x > max) max=x;
  return 0;
}

heal_self(x) {
  tell_room(environment(),HIM+"["+NORM+x+HIM+"]"+NORM);
  woopee+=x;
  if(x > max) max=x;
  return 0;
}
