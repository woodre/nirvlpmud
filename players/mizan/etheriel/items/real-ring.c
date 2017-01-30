inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("Ring of Ephidrena");
	set_short("Ring of Ephidrena");
	set_long("This must be the real thing.. carved from a solid chunk\n"+
	"of ruby... The ring is renown for its magic resistance properties,\n"+
	"its beauty, and among other things, it is one BIG ruby...\n");
	set_value(60000);
	set_ac(2);
	set_weight(1);
	set_type("ring");
	set_alias("ring");
	}
