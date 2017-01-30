inherit "/obj/monster";
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
  add_action("renew","renew");
  add_action("gkill","gkill");
}
int woopee;
int tries=0;
int total=0;
heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    woopee=2000-(this_object()->query_hp());
    total+=woopee;
    this_object()->heal_self(woopee);
    tries+=1;
    tell_room(environment(),"DAMAGE: "+woopee+" AVERAGE: "+(total/tries)+" TOTAL: "+total+"\n");
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
