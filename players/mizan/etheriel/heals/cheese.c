id(str) { return str == "cheese"; }
short() { return "A piece of cheese"; }
long() { write("This is a chunk of cheddar cheese.\n"); }
init() { add_action("eat","eat"); }
get() { return 1; }
query_weight() { return 1; }
query_value() { return 1200; }
eat(str) {
	if(!str) return 0;
	if(str != "cheese") return 0;
	this_player()->eat_food(2);
	write("You stuff the piece of cheese in your mouth and eat it whole.\n");
	say((this_player()->query_name())+" eats a chunk of cheese.\n");
	this_player()->heal_self(15);
	destruct(this_object());
	return 1;
	}
