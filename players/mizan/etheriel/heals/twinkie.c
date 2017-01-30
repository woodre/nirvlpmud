#include "std.h"
id(str) { return str == "twinkie"; }
short() { return "A twinkie"; }
get() { return 1; }
query_weight() { return 1; }
query_save_flag(){return 1;}
query_value() { return 10000; }
long() {
	write("This is a yummy looking Twinkie! It is renown throughout the\n"+
"mud for it's awesome healing power, suitable for all adventurers.\n"+
"(Don't eat too many or you'll get zits!)\n");
	}
init() {
	add_action("eat","eat");
	}
eat(str) {
	if(!str) return 0;
	if(str=="twinkie") {
		this_player()->heal_self(500);
		write("You wolf down a twinkie. You have ["+(this_player()->query_hp())+"] hp ["+(this_player()->query_sp())+"] sp.\n");
		say(capitalize(this_player()->query_name())+" eats a twinkie.\n");
		destruct(this_object());
		return 1;
	}
	return 0;
}
