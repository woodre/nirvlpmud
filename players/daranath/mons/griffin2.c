inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Female griffon");
  set_short("A sly female Griffon");
  set_alt_name("griffon");
  set_alias("female");
  set_race("beast");
  set_long("With the body of a lion and the upper half of an eagle\n"+
           "the griffon is quite popular within architecture and\n"+
           "paintings of lore. Its sharp beak and talons make for\n"+
           "a fearsome fighter, while its speed and great wingspan\n"+
           "generally keep it out of harms way.\n");
  set_level(16);
  set_al(-800);
  set_hp(325);
  set_wc(26);
  set_ac(12);
  set_aggressive(0);

  set_a_chat_chance(20);
  load_a_chat("The Griffon savagely defends its young.\n");
  load_a_chat("The griffon rakes at you with its claws.\n");

  set_chance(30);
  set_spell_dam(32);
  set_spell_mess2("The griffon tears at you with its claws, drawing blood.\n");
  set_spell_mess1("The griffon tears into its foe\n");

  gold=clone_object("obj/money");
  gold->set_money(random(1150)+500);
  move_object(gold,this_object());
}

