inherit "/obj/monster";

object target;
string who;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Hellhound");
  set_alt_name("hellhound");
  set_alias("hound");
  set_short("A Hellhound");
  set_long("A Hellhound.\n");
  set_race("hellhound");
  set_level(15);
  set_hp(225);
  set_ac(12);
  set_wc(20);
  set_al(-1000);
  set_aggressive(0);
  set_dead_ob(this_object());
  target = 0;
  who = "noone";
}

id(str) {
  return str == "hellhound" || str == "hound" || str == who+"'s hellhound";
}

query_ilstkarn() { return 1; }

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

sick(obj) {
  target = obj;
  who = target->query_real_name();
  target->attack_object(this_object());
  this_object()->attack_object(target);
  call_out("fake_beat", 3);
  return 1;
}

fake_beat() {
  if(!target || !present(target, environment(this_object()))) {
    destruct(this_object());
    return 1;
  }
  if(target->query_ghost()) {
    destruct(this_object());
    return 1;
  }
  if(target->query_attack() != this_object()) {
    tell_object(target, "The hellhound leaps back in your face!\n");
    target->attack_object(this_object());
    this_object()->attack_object(target);
  }
  call_out("fake_beat", 3);
  return 1;
}

monster_died() {
  object obj;
  obj = present("ferucche", environment(this_object()));
  if(!obj) {
    return 0;
  }
  obj->add_dog_killer(who);
  return 0;
}

