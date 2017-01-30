inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("guard");
	set_short("An Orc Elite Guard");
	set_long("The Elite Guard stands eight feet tall and is well armored,\n"+
		"proudly wearing the Red and Silver of the Clan. He is\n"+
		"a proud protector of the DeathBringer himself who has been\n"+
		"stationed here to protect the lair and its inhabitants.\n"+
		"He is ruthless in the execution of his duty.\n");
	set_level(20);
	set_hp(400+random(250));
	set_al(-250);
	set_aggressive(1);
	set_chat_chance(7);
	set_a_chat_chance(7);
	load_chat("The Elite Guard surveys the area carefully.\n");
	load_a_chat("The Elite Guard leaps to the defense of the lair.\n");
	set_chance(35);
	set_spell_mess1("The Elite Guard beats you to a bloody pulp.\n");
	set_spell_dam(30);
	armor = clone_object("players/pain/NEW/arm/pmail.c");
	move_object(armor,this_object());
	init_command("wear platemail");
	weapon = clone_object("players/pain/NEW/weap/mace2.c");
	move_object(weapon,this_object());
	init_command("wield mace");
	set_wc(30);
        set_ac(17);
}
