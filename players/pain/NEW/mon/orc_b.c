inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("orc");
	set_short("An Orc Berserker");
	set_long("The berserker stands just short of eight feet tall and is\n"+
		"clothed in the Red and Silver of the Clan. His chin is\n"+
		"covered in drool and his eyes have a crazed look. It is\n"+
		"rumored that the berserkers are the most fearsome fighters\n"+
		"in the Clan. You hope you won't find out.\n");
	set_level(20);
	set_hp(400+random(250));
	set_al(-250);
	set_aggressive(random(2));
	set_chat_chance(7);
	set_a_chat_chance(7);
	load_chat("The Berserker drools and mumbles incoherently.\n");
	load_a_chat("The Berserker begins shaking and shouting with rage.\n");
	set_chance(35);
	set_spell_mess1("The Berserker bites you!\n");
	set_spell_mess2("The Berserker tears the flesh from your bones.\n");
	set_spell_dam(30);
	armor = clone_object("players/pain/NEW/arm/bplate.c");
	move_object(armor,this_object());
	init_command("wear breastplate");
	set_wc(30);
        set_ac(17);
}
