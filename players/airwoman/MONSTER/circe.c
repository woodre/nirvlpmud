inherit"obj/monster";
reset(arg) {
  string chat_str;
  string a_chat_str;
  ::reset(arg);
  if(arg) return;
  if(!chat_str) {
    chat_str = allocate(2);
    a_chat_str = allocate(1);
    chat_str[0] = "Please LOVE me and not Hate me.\n";
    chat_str[1] = "Your eye's capture me in their orbs, my love for you is great.\n";
    a_chat_str[0] = "t\n";
  }
  set_name("circe");
  set_alias("circe");
  set_short("Circe the Siren");
  set_long(
	   "    This is the beautiful siren Circe.\n"
	   + "Odysseus made love with her, but be careful\n"
	   + "for when she is angry her emotions rule\n"
	   + "her mind and not logic.\n");
  set_level(20);
  set_race("human");
  set_hp(1000);
  set_wc(30);
  set_ac(17);
  load_chat(80,chat_str);
  load_a_chat(80,a_chat_str);
  set_chance(80);
  set_spell_dam(5);
  set_spell_mess1("Her anger rages into a whirlwind that blinds your eyes.");
  set_spell_mess2("Her emotions are strong and hot.");
  set_random_pick(10);
  add_money(1000);
}
