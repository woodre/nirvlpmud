inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("bard_darkness_object");
	set_short("A cloud of darkness");
	set_long("It is too dark to see.\n");
	set_weight(100);
	set_value(0);
	set_light(-2);
	/* <change by="Erasmios" date="2001-07-08"> */
	if (!root()) {
		call_out("dark", 360);
	}
	/* </change> */
}

dark()
{
	/* <change by="Erasmios" date="2001-07-08"> */
	if (environment()) {
		tell_room(environment(),
				  "The darkness which fills the room dissipates.\n");
	}
	/* </change> */
	destruct(this_object());
	return 1;
}
