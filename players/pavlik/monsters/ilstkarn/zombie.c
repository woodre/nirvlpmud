inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Zombie");
  set_alias("zombie");
  set_short("A Zombie");
  set_long(
  "The wasted body of a Zombie stands before you.  The mindless undead\n"+
  "shuffles forward, arms outstretched...\n");
  set_race("undead");
  set_level(15+random(5));
  set_hp(225+random(275));
  set_ac(12+random(15));
  set_wc(20+random(15));
  set_al(-random(1000));
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("The Zombie moans softly.\n");
  load_a_chat("Zombie sends you sprawling!\n");
  load_a_chat("The Zombie pummels you mercilessly!\n");
  load_a_chat("Zombie spits a foul stream of ichor at you!\n");
  load_a_chat("Zombie shuffles forward.\n");
  money = 500+random(500);
}

id(str) {
  return str == "zombie" || str == "ilstkarn_monster";
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

