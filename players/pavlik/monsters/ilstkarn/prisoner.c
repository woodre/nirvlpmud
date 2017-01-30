inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Prisoner");
  set_alias("prisoner");
  set_short("An Insane Prisoner");
  set_long(
  "This poor being has been locked away so long his mind is almost as\n"+
  "wasted as his wretched body.  The prisoner has no reasoning left,\n"+
  "all that remains is an urge to strike out and kill.\n");
  set_race("human");
  if(!random(2)) set_gender("male"); else set_gender("female");
  set_level(12+random(5));
  set_hp(150+random(250));
  set_ac(12+random(10));
  set_wc(15+random(15));
  set_al(-random(1000));
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("Spittle flies from the Prisoner's mouth.\n");
  load_a_chat("Prisoner curses uncontrollably.\n");
  load_a_chat("Prisoner clubs you with desperate force!\n");
  load_a_chat("Prisoner shrieks some nonsense.\n");
  load_a_chat("The Prisoner flails wildly.\n");
  money = 50 + random(100);
}

id(str) {
  return str == "prisoner" || str == gender || str == "ilstkarn_monster";
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

