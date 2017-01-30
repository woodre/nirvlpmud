inherit "obj/monster";

reset(arg)
{
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Wolf Rider");
  set_race("orc");
  set_alias("rider");
  set_short("A Wolf Rider");
  set_long("A Wolf Rider born and bred in Kor.\n");
  set_level(7);
  set_hp(105);
  set_al(-350);
  set_wc(11);
  set_ac(6);
  set_chat_chance(2);
  load_chat("Rider says: Let's kill em!\n");
  load_chat("Rider says: Let's let them go to Kor.\n");
  weapon=clone_object("/players/rumplemintz/weapon/orcsword");
  move_object(weapon,this_object());
}
