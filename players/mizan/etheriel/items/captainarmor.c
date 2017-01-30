inherit "obj/armor";

reset(arg) {
::reset(arg);
	set_short("A thick black rubber suit (With the letters CB on it)");
	set_long("This is a hard rubber suit that seems like it can stop bullets\n"+
"(As well as insulate against high voltages).\n");
	set_ac(3);
	set_value(2000);
	set_weight(2);
	set_alias("suit");
	set_name("suit");
	set_type("armor");
	}
