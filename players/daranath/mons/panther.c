inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("panther");
  set_short("Gor'Thazul's hunting Panther");
  set_alias("cat");
  set_race("feline");
  set_long("The panther is one of the great hunting cats that Gor'Thazul\n"+
           "has tamed for his own forays into Nirvana. Its dark brown fur\n"+
           "blends in perfectly along with the decor.\n");
  set_level(12);
  set_hp(295);
  set_al(-750);
  set_wc(21);
  set_ac(9);
  set_aggressive(1);

  set_a_chat_chance(15);
  load_a_chat("The great panther springs upon you with its powerful claws.\n");
  load_a_chat("The panther growls deeply at you during the fight.\n");
  load_a_chat("The panther slashes at you with its powerful claws.\n");

  gold=clone_object("obj/money");
  gold->set_money(random(300)+500);
  move_object(gold,this_object());
}

