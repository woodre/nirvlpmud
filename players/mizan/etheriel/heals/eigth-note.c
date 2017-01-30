id(str) { return str == "note" || str =="eigth"; }
short() { return "An eigth note"; }
long() { write("This is a eigth note could be 'played'.\n"); }
init() { add_action("playme","play"); }
playme(str) {
	int a;
	if(!str) return 0;
    if(str != "note") return 0;
	a=(this_player()->query_max_hp())/8;
	write("You play the note, and feel a bit better.\n");
	say((this_player()->query_name())+" plays a note and feels a bit better.\n");
	this_player()->heal_self(a);
	destruct(this_object());
	return 1;
	}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 900; }
query_duration() { return 2; }
