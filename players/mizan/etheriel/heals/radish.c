inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("radish");
	set_short("A radish");
	set_alias("radish");
	set_long("An ordinary looking radish.\n");
	set_eater_mess("You chomp down on a raw radish.\n");
	set_strength(10);
	}
}
