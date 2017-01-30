inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("muffin");
	set_short("A blueberry muffin");
	set_long("A yummy looking blueberry muffin");
	set_eater_mess("You gobble the muffin down... mmm! Just like Grandma used to make 'em!\n");
	set_strength(5);
}
}
