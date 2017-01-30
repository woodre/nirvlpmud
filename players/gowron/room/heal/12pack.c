int drinks;
short() { return "A 12 pack of duff beer."; }
long() {
	write("A 12 pack of duff beer.\n"+
	      "You have "+drinks+" left\n");
}
get() { return 1; }
drop() { return 0; }
query_value() { return 100*drinks; }
query_save_flag() { return 1; }
query_weight() { 
	if (drinks < 4) {
           return 2;
	}
	if (drinks < 8) {
           return 3;
	}
	if (drinks < 11) {
	   return 4;
	}
	if (drinks == 12) {
	   return 5;
	}
	else
           return drinks;
}
id(str) { return str == "12 pack"; }
reset(arg) {
	if (arg) return;
	drinks = 12;
}
init() {
	add_action("drink", "drink");
}
drink(str) {
	if ((!str) || (!str == "beer")) {
	   return 0;
	}
	if (!this_player()->drink_alcohol(14))
	   return 1;
	this_player()->heal_self(45+random(5));
	write("You drink a can of duff beer.\n");
	say(this_player()->query_name()+" drinks a duff beer.\n");
	if (drinks > 1) {
	   write("There are "+(drinks-1)+" remaining.\n");
	}
	else write("You drank the last beer.  Doh!\n");
	drinks--;
	if (drinks == 0)
	   destruct(this_object());
	return 1;
}
