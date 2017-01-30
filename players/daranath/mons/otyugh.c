inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("otyugh");
  set_short("An Otyugh rests amongst the filth");
  set_alias("otyu");
  set_race("gulguthra");
  set_long("The Otyugh has a huge, bloated body covered with rock-like\n"+
           "skin that is brownish gray in color. It stands on three legs\n"+
           "and have three eyes on a leaf-like stalk that moves side to\n"+
           "side, scanning the area, until it comes to a rest on you.\n");
  set_level(15);
  set_al(-750);
  set_hp(295);
  set_wc(24);
  set_ac(12);
  set_aggressive(0);

  set_a_chat_chance(15);
  load_a_chat("The otyugh bashes at you with its taloned tentacles.\n");
  load_a_chat("The otyugh smashes at you with its powerful body.\n");

  set_chance(30);
  set_spell_dam(25);
  set_spell_mess1("The otyugh lunges at its foe biting deeply, drawing blood.\n");
   set_spell_mess2("The otyugh rears up and bites you with its powerful jaws.\n");

  gold=clone_object("obj/money");
  gold->set_money(random(1250)+500);
  move_object(gold,this_object());
}

