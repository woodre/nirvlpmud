inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("footman");
	set_race("human");
	set_alias("footman");
	set_short("A Footman in the service of Bigelow");
	set_long("The Footman is a proud soldier in the service of Bigelow\n"+
		"and its citizens. He is the first line of defense against\n"+
		"the maurauding orc Clan.\n");
	set_level(10);
	set_hp(100+random(200));
	set_al(-150);
	set_aggressive(0);
	weapon = clone_object("players/pain/NEW/weap/sword.c");
	move_object(weapon,this_object());
	init_command("wield sword");
	set_wc(20);
	set_ac(12);
}
