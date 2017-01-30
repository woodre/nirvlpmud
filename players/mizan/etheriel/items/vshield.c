inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("shield of the order of the Breeders");
	set_short("Shield of the Order of the Breeders");
	set_long("The only item of the vapor knight's arsenal that is'nt see-through\n"+
	"in some way, this is a solid but rather heavy tower shield.\n");
	set_value(5000);
	set_ac(1);
	set_weight(3);
    set_type("shield");
	}
