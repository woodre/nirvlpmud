int drinks;
short() { return "A 6 pack of duff beer"; }
long() {
	write("A 6 pack of duff.  To heal yourself, type 'drink beer'\n"+
      "There are "+drinks+" beers left.\n");
}
get() { return 1; }
drop() { return 0; }
query_value() { return 100*drinks; }
query_weight() { return 2; }
query_save_flag() { return 1; }
id(str) { return str == "6 pack"; }
reset(arg) {
	if (arg) return;
	if (arg) 
           return;
	drinks = 6;
}
init() {
	add_action("drink", "drink");
}

drink(str) {
	if (!str)
	   return 0;
	if (!(str == "beer")) 
	   return 0;
	if (!this_player()->drink_alcohol(14))
	   return 1;
	this_player()->heal_self(45+random(5));
	write("You drink a can of duff beer.\n");
	say(this_player()->query_name()+" drinks a beer.\n");
	if (drinks > 1) {
	   write("There are "+(drinks-1)+" cans remaining.\n");
	}
	else write("You drank the last duff. Doh!\n");
	drinks--;
	if (drinks == 0) 
	   destruct(this_object());
	return 1;
}
