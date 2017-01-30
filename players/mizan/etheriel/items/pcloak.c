inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("purple cloak");
	set_short("The Purple Cloak of Ephidrena");
	set_long("This is a soft, fuzzy cloak made of some magical fleece.\n"+
	"It is very warm, and seems to offer decent protection as well!\n");
	set_value(1200);
        set_weight(1);
	set_ac(1);
	set_type("misc");
	set_alias("cloak");
	}
