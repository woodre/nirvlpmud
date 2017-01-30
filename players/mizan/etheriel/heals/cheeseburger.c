inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("cheeseburger");
	set_short("A cheeseburger");
	set_eater_mess("You scarf down a cheeseburger (Hmm.. its still warm!)\n");
	set_strength(20);
	set_value(130);
	set_eating_mess(" tears into a cheeseburger like there's no tomorrow!\n");
}
}
