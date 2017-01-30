inherit "obj/armor";

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("hair");
	set_short("Marge's Hair");
	set_long(format("This is Marge's hair.  It is a big blue bee"+
		 	"hive.  It is so big, you guess you can use "+
			"it as an helmet.\n",75));
	set_ac(1);
	set_value(50);
	set_weight(1);
	set_type("helmet");
}
