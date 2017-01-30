id(str) { return str == "bone"; }
short() { return "A chewing bone"; }
long() { write("This is a chewing bone meant for dogs.\n"+
	"Perhars even you can chew it as well.\n");
	}
init() { add_action("chew","chew"); }
chew(str) {
	if(!str) return 0;
	if(str != "bone") return 0;
	write("Mmmm! Yummy!\n");
	say("You see bone and make some unpleasant noises.\n");
	return 1;
	}
get() { return 1; }
query_value() { return 120; }
query_weight() { return 1; }
