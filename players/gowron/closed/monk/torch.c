inherit "obj/torch";

reset(arg) {
	::reset(arg);
	if (arg)
           return;
	set_name("Monk Light Source");
	set_fuel(100);
        set_weight(1);
}

