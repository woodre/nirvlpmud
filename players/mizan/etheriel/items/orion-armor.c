inherit "obj/armor";

reset(arg) {
::reset(arg);
	set_short("Carbolaminate Flak-Jacket");
	set_long("This ebony black armor, light as a feather, and hard as a diamond,\n"+
	"is awfully painful to wear, but you feel better knowing that there is\n"+
	"very little out there that can beat it in the form of protection.\n");
	set_ac(4);
	set_value(14000);
	set_weight(1);
	set_alias("jacket");
	set_name("jacket");
	set_type("armor");
	}
