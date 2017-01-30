inherit "obj/armor";

reset(arg) {
::reset(arg);
	set_short("Fuzzy boots");
	set_long("This is a pair of very comfortable fuzzy boots. You can't help but smile\n"+
	"happily as you bounce around in them. They make an interesting \n"+
	"squishing noise when you walk in them.\n");
	set_ac(1);
	set_value(300);
	set_weight(1);
	set_alias("boots");
	set_name("boots");
	set_type("boots");
	}
