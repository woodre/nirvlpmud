inherit "obj/monster";
reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("ikiryo");
  set_race("spirit");
  set_short("A Dangerous Spirit: An Ikiryo");
  set_long("A wispy figure of a woman.  She screams in torment and hatred.\n"+
      "She is the embodiment of the Wolf's hatred and fear.\n");
  set_hp(160);
  set_level(14);
  set_al(-500);
  weapon = clone_object("/players/mythos/awep/astralblade.c");
  move_object(weapon,this_object());
  init_command("wield blade");
  set_wc(17);
  set_ac(9);
  set_aggressive(1);

  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The spirit wails and weeps.\n");
  load_chat("You feel hatred emanating from the Ikiryo.\n");
  load_a_chat("The Ikiryo laughs and grows larger.\n");

  set_chance(10);
  set_spell_dam(10);
  set_spell_mess1("The Ikiryo screams and sends a shower of BLACK bolts at her attacker.\n");
  set_spell_mess2("The Ikiryo screams and sends a shower of dark BLACK bolts at you.\n");
}

