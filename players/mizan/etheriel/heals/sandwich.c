inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("sandwich");
	set_short("A ham sandwich");
	set_long("A tasty looking ham sandwich.");
	set_eater_mess("You scarf down the sandwich and feel better.\n");
	set_strength(20);
	}
}
