inherit "obj/monster";

reset(arg)
{
  object armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Horseback Rider");
  set_race("human");
  set_alias("rider");
  set_short("A Horseback Rider");
  set_long("A horse with a rider on top.\n");
  set_level(9);
  set_hp(135);
  set_al(500);
  set_wc(13);
  set_ac(7);
  weapon=clone_object("/players/rumplemintz/weapon/mace");
  move_object(weapon,this_object());
  armor=clone_object("/players/rumplemintz/armor/leather_armor");
  move_object(armor,this_object());
}
