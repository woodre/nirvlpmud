inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("banana");
	set_short("A banana");
	set_long("Duhhh... think REAL hard... now what is this thing??\n");
	set_eater_mess("You wonder if anyone around you think that eating a banana is a phallic symbol.\n");
	set_eating_mess(" unpeels a banana and shoves it up his face.\n");
	set_strength(5);
	set_value(1);
}
}
