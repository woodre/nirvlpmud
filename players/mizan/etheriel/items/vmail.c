inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("vapor knight's scalemail");
	set_short("Vapor Knight's Scalemail");
	set_long("This is an intriguing piece of armor. It is practically\n"+
	"transparent, yet it has nearly the protection of a suit of comparable\n"+
	"(and much heavier) steel scalemail armor!\n");
	set_value(18000);
	set_ac(4);
	set_weight(3);
	set_type("armor");
	set_alias("scalemail");
	}
