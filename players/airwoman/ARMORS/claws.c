inherit "obj/armor";
reset(arg){
	if (arg) return;
	set_name("Grendel's Claws");
	set_short("Grendel's Furry Claws");
        set_type("misc");
	set_alias("claws");
	set_ac(1);
	set_weight(1);
	set_value(100);
	set_long("These are the sharp claws of Grendel.\n"+
	"Maybe you should wear them to protect your hands?\n");
}
