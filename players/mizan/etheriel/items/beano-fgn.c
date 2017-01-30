id(str) { return str == "figure" || str == "figurine"; }
object beano;
short() { return "A Beano figurine"; }
long() {
	write("This is a Beano figurine. It looks just like a live beano would.\n"+
	"It looks like you could 'rub figurine'.\n");
	}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 400; }

init() {
	add_action("rub","rub");
	}

rub(str) {
	if(!str) return 0;
	if(str=="figurine") {
	write("You rub the figurine, and it comes to life!\n");
	say((this_player()->query_name())+"rubs a statue, and it springs to life!\n");
	beano=clone_object("players/mizan/mbv2/beasties/beano-shitflinger.c");
	move_object(beano, environment(this_player()));
	destruct(this_object());
	return 1;
	}
return 0;
}
