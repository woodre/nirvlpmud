inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("cookie");
	set_short("A Chocolate Chip Pentagram Cookie");
	set_eater_mess("Yummy! Now was'nt that *BURP* good?\n");
	set_long("A chocolate chip cookie in the shape of a pentagram");
	set_strength(1);
	}
}
