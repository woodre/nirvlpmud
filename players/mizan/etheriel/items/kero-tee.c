inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return 0;
	set_name("tee-shirt");
	set_short("A tee-shirt with the letter 'K' emblazoned on it");
	set_long("This is a regular cotton tee with a pink 'K' on it.\n");
	set_value(200);
	set_ac(1);
	set_type("misc");
	set_alias("shirt");
	}
