id(str) { return str == "flaming moe"; }
long() {
	write("This is a flaming moe drink.  It is a *very* powerful heal.\n");
}
get() { return 1; }
drop() { return 0; }
query_save_flag() { return 1; }
query_weight() { return 4; }
query_value() { return 2000; }

init() {
	add_action("drink", "drink");
}

drink(str) {
	if (!str) {
	   return 0;
	}
	if (!(str == "moe")) 
	   return 0;
	this_player()->heal_self(380);
	say(this_player()->query_name()+" drinks a flaming moe "+
					" looks *much* better!\n");
        destruct(this_object());
        return 1;
}
short() { return "Flaming Moe"; }
