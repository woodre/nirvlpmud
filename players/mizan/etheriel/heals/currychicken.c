inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("chicken");
	set_short("A chunk of curry chicken");
	set_eater_mess("Yow! Spicy as hell but it felt GOOD!\n");
	set_long("A chunk of heavily spiced curry chicken. Looks harmless.\n");
	set_strength(10);
	}
}
