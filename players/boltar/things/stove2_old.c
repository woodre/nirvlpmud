inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_long("A stove. ");
	set_short("A stove");
	set_name("stove");
	set_weight(300);
	set_max_weight(6);
	set_value(12);
    }
}
