inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return 0;
	set_name("dopey red hat");
	set_short("A dopey red hat");
	set_long("This is a silly-looking red hat made of a fuzzy yarn.\n");
	set_value(200);
	set_ac(1);
	set_type("helmet");
	set_alias("hat");
	}
