inherit "obj/armor";

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("headphones");
	set_short("Auto's Headphones");
	set_long("Autos headphones.  They are so thick they could probably "+
		 "make a good armor.\n");
	set_ac(1);
	set_value(50);
	set_weight(2);
	set_type("helmet");
}
