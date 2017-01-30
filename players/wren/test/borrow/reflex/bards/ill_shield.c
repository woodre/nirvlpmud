/* <change by="Erasmios" date="2001-07-05"> */
inherit "/players/saber/armor/armor3.c";
reset(arg)
{
	::reset(arg);
	set_name("illusion_cloak");
	set_short();
	set_long("A cloak of illusion.\n");
	set_weight(0);
	set_value(0);
	/* this is a hack */
	set_ac(0);
	set_type("magic");
	set_ac(2);
	/* end hack */
}

start_self_destruct(int tics)
{
	call_out("count_down", tics);
}
/* </change> */

drop()
{
	return 1;
}

get()
{
	return 1;
}

count_down()
{
	tell_room(environment(this_object()), "Something has changed.\n");
	say("Your cloak of illusion fades away.\n");
	command("remove illusion_cloak", this_player());
	destruct(this_object());
	return 1;
}
