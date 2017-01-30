id(str) { return str == "herring"; }
short() { return "A pickled herring"; }
long() { write("This is a seasoned fish. Nothing too special about it\n"+
	"except for it being a mite too limp..\n"); }
init() { add_action("play","eat"); }
play(str) {
	int a;
	if(!str) return 0;
	if(str != "herring") return 0;
	a=(this_player()->query_max_hp())/3;
	write("You drop the fish into your mouth and it slides down your throat.\n");
	say((this_player()->query_name())+" eats a pickled herring.\n");
	this_player()->heal_self(a);
	destruct(this_object());
	return 1;
	}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 10000; }
