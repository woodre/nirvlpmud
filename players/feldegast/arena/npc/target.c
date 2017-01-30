inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("target");
  set_short("A wooden practice target");
  set_long(
    "This is a wooden practice target in the shape of a man.  It is used\n"+
    "by gladiators to practice their attacks.\n"
  );
  set_gender("male");
  set_race("golem");
  set_level(1);
  set_wc(0);
  set_ac(0);
  set_hp(200);
  set_al(0);
}
int woopee;
heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    woopee=2000-(this_object()->query_hp());
    this_object()->heal_self(woopee);
  }
}
