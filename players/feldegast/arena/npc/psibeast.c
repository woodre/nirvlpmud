
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Psi-beast");
  set_alt_name("beast");
  set_short("Psi-beast");
  set_long(
"A large indistinct grey mist that seeps and blows about the room\n"+
"in the vague form of some sort of huge demonic insect.\n");
  set_race("spirit");
  set_level(10);
  set_wc(18);
  set_ac(10);
  set_hp(300);
  set_al(-200);
  add_money(80000);
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    attacker_ob->add_exp(-random(50));
    tell_object(attacker_ob,
    "You feel a lance of pain as the psi-beast feasts on your mind.\n");
  }
}
