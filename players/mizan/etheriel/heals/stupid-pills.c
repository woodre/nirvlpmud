inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("pills");
	set_short("Stupidity Pills");
	set_alias("pills");
	set_long("A bottle of Stupidity pills (Do you need them? *smile*).\n");
	set_eater_mess("The pills seem to take effect before you eat them. You chug the whole bottle.\n");
	set_eating_mess(" downs a whole bottle of Stupidity pills.\n");
	set_strength(5);
	set_value(50);
	}
}
