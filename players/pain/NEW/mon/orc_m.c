inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("orc mage");
	set_race("orc");
  set_alias("mage");
	set_short("An Orc Mage");
	set_long("The mage stands just short of eight feet tall and is\n"+
		"clothed in the Red and Silver of the Clan. He begins to\n"+
		"chant quietly as you look at him, obviously preparing to\n"+
		"cast some spell or other.\n");
	set_level(20);
	set_hp(400+random(200));
	set_al(-150);
	set_aggressive(0);
	set_chat_chance(7);
	set_a_chat_chance(7);
	load_chat("The mage begins chanting, attempting a new spell.\n");
	load_chat("The mage grins as his skills improve.\n");
	load_a_chat("Orc Mage says: You should not have disturbed me fool.\n");
	set_chance(35);
	set_spell_mess1("The Mage fires a deathray at you.\n");
	set_spell_mess2("The Mage hits you with a fireball.\n");
	set_spell_dam(30);
	armor = clone_object("players/pain/NEW/arm/hood.c");
	move_object(armor,this_object());
	init_command("wear cloak");
	set_wc(30);
        set_ac(17);
}
