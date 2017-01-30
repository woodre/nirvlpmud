inherit "obj/monster";

reset(arg)
{
  object armor, gold;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("orc");
	set_short("An Orc Worker");
	set_long("The orc stands just short of seven feet tall and is\n"+
		"clothed in grimy work clothing. He toils for the Clan\n"+
		"tirelessly to earn his keep and protection.\n");
	set_level(12);
	set_hp(150+random(200));
	set_al(-75);
	set_aggressive(0);
	gold = clone_object("obj/money");
	gold->set_money(200);
	move_object(gold,this_object());
	armor = clone_object("players/pain/NEW/arm/boots");
	move_object(armor,this_object());
	init_command("wear boots");
	set_wc(17);
        set_ac(10);
}
