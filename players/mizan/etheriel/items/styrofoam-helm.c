inherit "obj/armor";

reset(arg) {
::reset(arg);
	set_short("A styrofoam helmet");
	set_long("This is an extremely light (but definitely not fashionable)\n"+
"piece of headgear. An inscription on it reads: 'Made in Hong Kong'.\n");
	set_ac(1);
	set_value(800);
	set_weight(1);
	set_alias("styrofoam");
	set_name("helmet");
	set_type("helmet");
	}
