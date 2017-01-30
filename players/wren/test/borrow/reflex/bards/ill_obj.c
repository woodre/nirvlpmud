inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("illusion");
	set_short("illusion");
	set_alias("illusion");
	set_long("An illusion.\n");
	set_weight(100);
	set_value(0);
	/* <change by="Erasmios" date="2001-07-08"> */
	if (!root()) {
		call_out("ill_count", random(1000));
	}
	/* </change> */
}

long(){
	write("An Illusion.\n");
	if(present("bard_obj", this_player())){
		write("As a Bard you may 'dispell illusion'.\n");
	}
	return 1;
}


ill_count()
{
	/* <change by="Erasmios" date="2001-07-08"> */
	if (environment()) {
		tell_room(environment(), "Something has changed.\n");
	}
	/* </change> */
	destruct(this_object());
	return 1;
}

drop()
{
	return 1;
}

get()
{
	return 1;
}

can_put_and_get()
{
	return 1;
}

init(){
	add_action("dispell", "dispell");
}

dispell(str){
	if(!present("bard_obj", this_player())) return;
	if(!str){
		 write("dispell what?\n");
		 return 1;
	}
	if(str == "illusion"){
		write("You wave a hand and the illusion dissipates.\n");
		say(this_player()->query_name()+" waves "+this_player()->query_possessive()+""+
			"hand. \nSomething in the room changes.\n");
		destruct(this_object());
		return 1;
	}
	write("dispell what?\n");
	return 1;
}