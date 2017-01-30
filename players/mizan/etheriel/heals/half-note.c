id(str) { return str == "note" || str == "half"; }
short() { return "A half note"; }
long() { write("This is a half note. It looks like it could be 'played'.\n"); }
init() { add_action("play","play"); }
play(str) {
	int a;
	if(!str) return 0;
    if(str != "note") return 0;
	a=(this_player()->query_max_hp())/2;
	write("You play the note, and feel much better.\n");
	say((this_player()->query_name())+" plays a note and feels much better.\n");
	this_player()->heal_self(a);
	destruct(this_object());
	return 1;
	}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 10000; }
query_duration() { return 8; }
