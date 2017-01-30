summon_pet(str)
{
	object ob, ob2, ob3;
	string animal_type, OB;
	string name, xname;
    object petname;
	int length;
	int i;
	string named;
	string named2;
   int notfirst;
#define BBB move_object(ob,environment(this_player()))
#define ENVV environment(this_player())

	if (!str) {
		write("Animal <type>    <see animal_list>\n");
		return 1;
	}

	if (sscanf(str, "%s %s", name, xname) != 2) {
		write("Animal <type> <name>\n");
		return 1;
	}
 	named = lower_case(xname);
	named2 = strlen(xname);
	i=0;
	while(i < named2) {
		if (named[i] < 'a' || named[i] > 'z'){
			write("Invalid characters in name.\n");
			return 1;
		}
		i += 1;
	}
	xname = lower_case(xname);
	length = strlen(xname);
	if (length > 11) {
		write("Pet name is too long.\n");
		return 1;
	}
	if (name == "raven") {
		if (spell(-149, 2, 50) == -1)
			return 0;
		ob = clone_object("/players/guilds/bards/pet/raven.c");
	} 
	else if (name == "hawk") {
		if (spell(-149, 4, 50) == -1)
			return 0;
		ob = clone_object("/players/guilds/bards/pet/hawk.c");
	} 
	else if (name == "drake") {
		if (spell(-149, 6, 50) == -1)
			return 0;
		ob = clone_object("/players/guilds/bards/pet/drake.c");
	} 
	else if (name == "phoenix") {
		if (spell(-149, 8, 50) == -1)
			return 0;
		ob = clone_object("/players/guilds/bards/pet/phoenix.c");
	} 
	else if (name == "faerie" && TP->query_level() > 19) {
		if (spell(-149, 4, 50) == -1)
			return 0;
		ob = clone_object("/players/guilds/bards/pet/faerie.c");
	} 
	else if (name == "brownie" && TP->query_level() > 19) {
		if (spell(-149, 4, 50) == -1)
			return 0;
		ob = clone_object("/players/guilds/bards/pet/brownie.c");
	} 
	else {
		write("That is not a bardic animal.\n");
		return 1;
	}
   if(this_object()->my_pet()){
        notfirst = 1;
        (this_object()->my_pet())->bye2();
   }

	call_other(ob, "set_master_name", this_player()->query_real_name());
	call_other(ob, "set_alt_name", xname);
	call_other(TO, "set_pet_name", xname);
	BBB;
    my_pet(ob);

	tell_room(environment(TP), "\n\n");
	write("You play a tune of summoning upon your " +
		TO->query_instrument() + ".\n");
	say(tp + " plays a tune upon " + TP->query_possessive() + " " +
		TO->query_instrument() + ".\n");

	if (name == "raven") {
		tell_room(ENVV, "A raven flies in and circles " + tp + ".\n");
	}
	if (name == "hawk") {
		tell_room(ENVV, "An hawk flies in and circles " + tp + ".\n");
	}
	if (name == "drake") {
		tell_room(ENVV,
			"A shadow crosses over you as a small drake descends from the sky\n"
			+ "and circles " + tp +
			" three times before landing upon " +
			TP->query_possessive() + " shoulder.\n");
	}
	if (name == "phoenix") {
		if (present("corpse", environment(TP))) {
			ob = present("corpse", environment(TP));
			if (ob->short() == "corpse of Phoenix") {
				destruct(ob);
				tell_room(ENVV,
					"The corpse of the Phoenix is engulfed in an explsion of crimson fire.\n\n"
					+
					"A Phoenix rises from the ashes of its corpse.\n\n");
			}
		}
		tell_room(ENVV,
			"A column of crimson fire descends from the sky.\n\n" +
			"A phoenix rises from the ashes of the fire and flies over to "
			+ tp + ".\n");
	}
   if(!notfirst)
	call_other(TP, "add_spell_point", -50);
	return 1;
}

set_pet_name(str)
{
	pet_name = str;
}

query_pet_name()
{
	return pet_name;
}
