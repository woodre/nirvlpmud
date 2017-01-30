inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Fire Demon");
  set_alias("demon");
  set_short("minor Fire Demon");
  set_long(
  "A small but nasty Fire Demon.  Minor Fire Demon's tend to travel in small\n"+
  "hoards and will only attack when the odds appear to be greatly in their favor.\n"+
  "They are wicked little creatures that are known primarily for their slyness.\n"+
  "Minor Fire Demon's are cowards at heart.\n");
  set_race("fire demon");
  set_level(14);
  set_hp(210);
  set_ac(11);
  set_wc(19);
  set_al(-random(1000));
  set_aggressive(0);
  money = 500+random(350);
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

do_help(obj) {
  this_object()->attack_object(obj);
  return 1;
}

