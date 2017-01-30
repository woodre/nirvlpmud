inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	set_name("slingshot");
	set_short("Bart's Slingshot");
	set_long(format("This is the slingshot that once "+
			"belonged to Bart Simpson.  It looks "+
			"like a decent weapon.\n",75));
	set_class(10+random(5));
	set_weight(random(3)+1);
	set_value(500);
}
