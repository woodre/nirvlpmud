inherit "obj/monster";

reset(arg)
{
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Orc of Kor");
  set_race("orc");
  set_alias("orc");
  set_short("An Orc of Kor");
  set_long("An Orc born and bred in Kor.\n");
  set_level(7);
  set_hp(105);
  set_al(-350);
  set_wc(11);
  set_ac(6);
  set_chat_chance(2);
  load_chat("Orc says: Let's kill em!\n");
  load_chat("Orc says: Let's let them go to Kor.\n");
  weapon=clone_object("/players/rumplemintz/weapon/orcsword");
  move_object(weapon,this_object());
}
