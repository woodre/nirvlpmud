inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("squash");
	set_short("A squash");
	set_alias("squash");
	set_long("An ordinary looking squash.\n");
	set_eater_mess("You chomp down on a raw squash.\n");
	set_strength(10);
	}
}
