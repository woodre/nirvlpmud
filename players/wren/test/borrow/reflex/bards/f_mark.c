inherit "/obj/monster";

reset(arg)
{
	::reset(arg);
	if (!arg) {
		set_name("faerie");
		set_short();
		set_long
			("You see many eyes peering out at you from the forest.\n");
		set_level(2);
		set_ac(3);
		set_wc(6);
		set_hp(30);
		set_al(-10);
		set_aggressive(0);
		set_chat_chance(2);
		load_chat("You hear light voices whispering in the woods.\n");
	}
}
