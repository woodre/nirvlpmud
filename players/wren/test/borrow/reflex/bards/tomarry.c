
#define prompt ("->> ")
#include "living.h"
string alias, info, spouse, player;
int player_yes, spouse_yes, ceremony_in_progress;
object player_ob, spouse_ob;

short()
{
	return "A minister";
}

get()
{
	return 0;
}

long()
{
	write("He is a kindly and very old man. He smiles at you.\n");
	write("\nType \"marry help\" and \"marry <who>.\"\n");
}


reset(arg)
{
	object ob;

	if (arg)
		return;
	name = "minister";
	alias = "man";
	cap_name = "Minister";
	msgout = "leaves";
	msgin = "enters";
	level = 100;
	is_npc = 1;
	alignment = 100000;
	weapon_class = WEAPON_CLASS_OF_HANDS;
	max_hp = 8950;
	hit_point = 8950;
	experience = 3000000;
	mmsgout = "disappears in a puff of smoke";
	mmsgin = "arrives in a puff of smoke";
	armor_class = 1000;
	player_yes = 0;
	spouse_yes = 0;
	enable_commands();
	spell_points = 8950;
	ob = clone_object("obj/soul");
	move_object(ob, this_object());
}

id(str)
{
	return str == name || str == alias || str == info;
}

query_info()
{
	return info;
}

init()
{
	add_action("marry", "marry");
}

marry(str)
{
	if (!str)
		return 0;
	if (str == "help") {
		if (!efun::query_verb())
			say("\n");
		say(format
			(cap_name +
			 " says: I will marry you and your beloved for the " +
			 "price of a mere 100 coins. Simply type \"marry <spouse>\", and I will "
			 + "perform the ceremony.\n"));
		if (!efun::query_verb())
			say(prompt);
		return 1;
	}
	if (!present(str)) {
		say(format
			(cap_name +
			 " says: I'm sorry, but that person isn't here.\n"));
		return 1;
	}
	if (present("wedding ring", this_player()) || present("wedding ring",
														  present(str))) {
		say(format
			("\n" + cap_name +
			 " says: Only the unmarried may be joined!\n"));
		return 1;
	}
	if (this_player()->query_money() < 100) {
		say(cap_name + " says: I'm afraid you don't have enough money.\n");
		return 1;
	}
	if (!ceremony_in_progress)
		ceremony(this_player(), present(str));
	else
		say(format
			(cap_name + " says: I am already performing a ceremony.\n"));
	return 1;
}

catch_tell(str)
{
	string a, b, c;

	if (player && (sscanf(str, "%s says:%sdo%s", a, b, c) == 3 ||
				   sscanf(str, "%s says%syes%s", a, b, c) == 3)) {
		if (a == player)
			player_yes = 1;
		if (a == spouse)
			spouse_yes = 1;
		if (ceremony_in_progress && player_yes && spouse_yes)
			call_out("pronouncement", 2);
	} else if (sscanf(str, "%s says:%shelp%s", a, b, c) == 3 ||
			   sscanf(str, "%s says:%smarry%s", a, b, c) == 3) {
		call_out("marry", 1, "help");
		return 1;
	}
}

ceremony(me, you)
{
	if (!player) {
		player = me->query_name();
		spouse = you->query_name();
		player_ob = me;
		spouse_ob = you;
		ceremony_in_progress = 1;
	}
	me->add_money(-100);
	say(format
		(cap_name + " says: Dearly beloved, we are gathered here today " +
		 "to witness the union of " + capitalize(player) + " and " +
		 capitalize(spouse) + ".\n"));
	call_out("ceremony_two", 2);
	call_out("stop_ceremony", 100);
}

ceremony_two()
{
	say(format
		("\n" + cap_name + " says: Do you, " + capitalize(player) + ", " +
		 "promise to love " + capitalize(spouse) +
		 " until the end of your days?" + "\n"));
	say(format
		(prompt + "\n" + cap_name + " says: And do you, " + spouse +
		 ", promise the same?\n"));
	tell_room(environment(), prompt);
}

pronouncement()
{
	object ring1, ring2;

	say(format
		("\n" + cap_name + " says: Then by the power vested in me by " +
		 "Bastion the archmage and and gods of Nirvana, I join you in the bonds "
		 + "of matrimony.\n"));
	say(format
		(prompt + "\n" + cap_name + " says: Take these rings " +
		 "as symbols of your enduring affection.\n"));
	tell_room(environment(), prompt);
	ring1 = clone_object("players/bastion/closed/ring");
	ring2 = clone_object("players/bastion/closed/ring");
	ring1->set_spouse(spouse_ob->query_real_name());
	ring2->set_spouse(player_ob->query_real_name());
	move_object(ring1, present(player_ob));
	move_object(ring2, present(spouse_ob));
	remove_call_out("stop_ceremony");
	log_file("bastion.marry", player + " married " + spouse + " " +
			 ctime() + "\n");
	player = 0;
	spouse = 0;
	ceremony_in_progress = 0;
	player_ob = 0;
	spouse_ob = 0;
	player_yes = 0;
	spouse_yes = 0;
	return 1;
}

stop_ceremony()
{
	say(format
		("\n" + cap_name + " says: Since you have not answered I will " +
		 "end the ceremony.\n"));
	say(prompt);
	player = 0;
	spouse = 0;
	ceremony_in_progress = 0;
	player_ob = 0;
	spouse_ob = 0;
	player_yes = 0;
	spouse_yes = 0;
}
