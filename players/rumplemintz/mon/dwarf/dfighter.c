inherit "obj/monster";

reset(arg)
{
  object armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Dwarven Fighter");
  set_race("dwarf");
  set_alias("fighter");
  set_short("A Dwarven Fighter");
  set_long("A nimble fighter produced by the Dwarf Lords.\n");
  set_level(9);
  set_hp(135);
  set_al(-500);
  set_wc(13);
  set_ac(7);
  weapon=clone_object("/players/rumplemintz/weapon/baxe");
  move_object(weapon,this_object());
  armor=clone_object("/players/rumplemintz/armor/dcloak");
  move_object(armor,this_object());
}
