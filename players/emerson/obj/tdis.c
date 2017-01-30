id(str) { return str=="dispenser"; }
reset() {}
short() {
	return "A tampon dispenser";
}
long() {
write("You can purchase tampons from the dispenser for 500 coins.\n"+
"Just type 'buy tampon' to get a 100% effective tampon.  Emerson's\n"+
"tampons are guaranteed to work or your money back! (only valid when used as\n"+
"directed).\n");
}
init() {
	add_action("buy","buy");
}
buy(str) {
	object tampon;
	if(str=="tampon") {
	if(this_player()->query_money() < 500) {
	write("You don't have enough gold coins!\n");
	return 1;
	}
	if(!call_other(this_player(), "add_weight", 1)) {
	write("You can't carry that much.\n");
	return 1;
	}
	this_player()->add_money(-500);
	tampon=clone_object("/players/emerson/armor/tampon.c");
	move_object(tampon, this_player());
	write("You put your coins in the machine and get a tampon.\n");
	say(capitalize(this_player()->query_real_name())+" buys a tampon from the dispenser.\n");
	return 1;
	}
}
get() { return 0; }
