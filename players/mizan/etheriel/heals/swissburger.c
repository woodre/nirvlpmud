inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("burger");
	set_short("A bacon-double swiss cheeseburger (warm)");
	set_long("A bacon-double swiss cheesburger... mmmm.... what to think you do with it?\n"+
	"sit on it??? *grin*\n");
	set_eater_mess("You gobble down the thing in four bites. *BURP!*\n");
	set_eating_mess(" pigs out on a bacon-double special and burps rudely.\n");
	set_value(300);
	set_strength(40);
}
}
