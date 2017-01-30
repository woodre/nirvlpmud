inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("mangled platemail");
	set_short("Beat-up platemail armor");
	set_long("This is the smelliest, crummiest, most decrepit and worn out\n"+
	"piece of platemail armor you have ever seen. Its joints are stiff and\n"+
	"fungled, and is generally in a state of severe disrepair.\n");
	set_value(100);
	set_weight(4);
	set_ac(-2);
	set_type("armor");
	set_alias("platemail");
	}
