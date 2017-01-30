id(str) { return str == "duff"; }

short() { return "A can of duff"; }
long() {
	write ("A can of duff beer.  You feel like it has great healing power.\n");
}
get() { return 1; }
drop() { return 0; }
query_value() { return 0; }
query_save_flag() { return 1; }
query_weight() { return 1; }

init() {
	add_action("drink", "drink");
}

drink(str) {
	if (!str) 
	   return 0;
	if (!(str == "duff"))
	   return 0;
	if (!this_player()->drink_alcohol(14))
	  return 1;
	this_player()->heal_self(45+random(5));
	say(this_player()->query_name()+" drinks a can of duff\n");
	destruct(this_object());
	return 1;
}
