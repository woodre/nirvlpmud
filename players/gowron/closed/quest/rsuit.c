inherit "obj/armor";

reset(arg) {
	if (arg)
	   return;
	set_name("suit");
	set_alias("radiation suit");
	set_short("A radiation protection suit");
	set_long("This is a radiation protection suit, worn by some "+
		 "by some worker at the plant.  You probably want to "+
		 "wear it when you're inside the plant.\n");
	set_ac(2);
	set_type("armor");
	set_weight(2);
	set_value(200);
}

