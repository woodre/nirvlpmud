id(str) { return str == "note" || str == "whole"; }
short() { return "A whole note"; }
long() { write("This is a whole note. It looks like it could be 'played'.\n"); }
init() { add_action("play","play"); }
play(str) {
	if(!str) return 0;
  if(str != "note") return 0;
	write("You play the note, and feel a whole lot better.\n");
	say((this_player()->query_name())+" plays a note and feels a whole lot better.\n");
	this_player()->heal_self(1000);
	destruct(this_object());
	return 1;
	}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 10000; }
query_duration() { return 16; }
