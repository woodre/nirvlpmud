inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("snake");
  set_alias("monster");
  set_alt_name("giant snake");
  set_race("creature");
  set_short("Giant Black Snake");
  set_long("A giant black snake- over 20 feet long and \n"+
           "as think as a tree trunk.  Its mesmerizing eyes\n"+
           "gleam and its fangs flash!\n");
  set_hp(500);
  set_level(20);
  set_al(-1000);
  set_wc(30);
  set_ac(17);
  set_heal(5,20);
  set_a_chat_chance(10);
  load_a_chat("A snake lashes out!\n");
  load_a_chat("A Snake strikes with blinding speed!\n"); 
  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("A snake lashes out!\n");
  set_spell_mess2("A snake lashes out and bites deeply into your flesh!\n"); 
}

