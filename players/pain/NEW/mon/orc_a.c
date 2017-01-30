inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("orc");
	set_short("An Orc Axeman");
	set_long("The axeman stands just short of eight feet tall and is\n"+
		"clothed in the Red and Silver of the Clan. He smirks at\n"+
		"you as you look at him. He carries a huge axe, and you\n"+
		"know that he is very proficient with it.\n");
	set_level(18);
	set_hp(300+random(200));
	set_al(-150);
	set_aggressive(1);
	weapon = clone_object("players/pain/NEW/weap/axe.c");
	move_object(weapon,this_object());
	init_command("wield axe");
	set_wc(20);
        set_ac(12);
}
