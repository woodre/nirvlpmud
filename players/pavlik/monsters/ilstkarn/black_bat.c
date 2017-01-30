inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Large Bat");
  set_alias("black bat");
  set_short("A Large Bat");
  set_long(
  "You have disturbed a large black bat from its slumber and it does\n"+
  "not appear to be very happy about it!  The bat chitters angrily\n"+
  "as it swoops down on you from above.\n");
  set_race("bat");
  set_level(15+random(5));
  set_hp(225+random(275));
  set_ac(14+random(15));
  set_wc(17+random(15));
  set_al(-random(1000));
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("The large bat swoops down from above!\n");
  load_a_chat("Large bat bites into you!\n");
  load_a_chat("The Large bat rakes your skin with sharp claws!\n");
  load_a_chat("The swift bat avoids your clumsy attacks.\n");
}

id(str) {
  return str == "bat" || str == "black bat" || str == "large bat" ||
  str == "ilstkarn_monster";
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  write("The bat is too upset to stop fighting.\n");
  return;
}

init() {
  ::init();
  add_action("nope","north");
  add_action("nope","south");
  add_action("nope","east");
  add_action("nope","west");
}

nope() {
  write("The angry bat will not let you leave!\n");
  return 1;
}

