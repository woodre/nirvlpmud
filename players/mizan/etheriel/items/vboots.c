inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("astralglides");
	set_short("A pair of Astralglides (boots)");
	set_long("Funny.. these things resemble sneakers, but they are cut higher,\n"+
	"giving the ankle more support, and seem to offer a decent amount of\n"+
	"protection, etc.\n");
	set_value(1000);
	set_ac(1);
	set_type("boots");
	set_alias("boots");
	}
