id(str) { return str == "zokball"; }
short() { return "A zokball"; }
long() {
  write("This thing seems to have no real purpose. It does'nt bounce,\n"+
	"but offers little resilience when squeezed. It's too small\n"+
	"to juggle, and too big to use as a marble, and for some reason\n"+
	"you feel like eating it.\n"); }
init() { add_action("eat","eat"); }
get() { return 1; }
query_weight() { return 1; }
query_value() { return 200; }
eat(str) {
	if(!str) return 0;
	if(str != "zokball") return 0;
	this_player()->eat_food(1);
	write("Yum. The zokball actually tasted pretty good.\n");
	say((this_player()->query_name())+" eats a zokball whole.\n");
	this_player()->heal_self(9);
	destruct(this_object());
	return 1;
	}
