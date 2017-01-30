inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("defender");
  set_race("human");
  set_alias("guard");
  set_short("A defender of the hall");
  set_long("   This man stands pristine in shiny silver, rigidly at\n"+
	   "attention. The man looks deadly even without motion, and\n"+
	   "remains vigilant against intruders.\n");
  set_level(10);
  set_hp(200);
  set_al(-400);
  set_wc(17);
  set_ac(10);
  weapon=clone_object("/players/anshar/hall/wep/halberd");
  move_object(weapon,this_object());
  init_command("wield halberd");
  armor=clone_object("/players/anshar/hall/armor/chain1");
  move_object(armor,this_object());
  init_command("wear armor");
}
