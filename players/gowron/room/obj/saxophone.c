id(str) { return str == "saxophone"; }
short() { return "Lisa's Saxophone"; }
long() {
	write("This is Lisa's pride and joy.  Her saxophone.\n");
}
query_weight() { return 2; }
query_value() { return 50; }

get() { return 1; }
reset(arg) {
	if (arg)
	   return;
}

play(str) {
	if ((!str) && !(str == "saxophone")) 
           return 0;
	write("You play the blues on the saxophone..\n");
	return 1;
}

init() {
	add_action("play", "play");
}

