inherit "obj/monster";
reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("ryo");
  set_short();
  set_alias("ryo");
  set_race("spirit");
  set_long("A wispy wraith of a woman who was cut down for being a Taira.\n");
  set_hp(150);
  set_level(10);
  set_al(-750);
  set_wc(15);
  set_ac(8);
  set_aggressive(0);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Something fliters by.\n");
  load_chat("The ryo screams a silent scream.\n");
  load_a_chat("\n       ****** A N G E R ******\n\n");

  set_chance(15);
  set_spell_dam(18);
  set_spell_mess1("Mist gathers.\n");
  set_spell_mess2("\nSOMETHING stings you.\n");
 move_object(clone_object("/players/mythos/amisc/mirror.c"),this_object());
}

