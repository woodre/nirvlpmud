
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("calis");
  set_alt_name("sakadi");
  set_short("Calis Sakadi");
  set_long(
"Calis Sakadi is the youngest of the three Sakadi brothers and the\n"+
"least interested in managing the family business.  He runs this store\n"+
"for his brother, Abdullah Sakadi because it gives him the opportunity\n"+
"to meet such interesting people.  Calis is tall and broadshouldered\n"+
"with dreamy looking blue eyes and a cleft chin.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(18);
  set_ac(8);
  set_hp(190);
  set_al(500);
  set_chat_chance(4);
  load_chat("Calis absentmindedly stares out the window.\n");
  load_chat("Calis says: Oh, can I help you?\n");
  set_a_chat_chance(6);
  load_a_chat("Calis punches you weakly.\n");
  load_a_chat("Calis hits your fist with his face.\n");
  load_a_chat("Calis screams for help.\n");
  add_money(500+random(200));
}
