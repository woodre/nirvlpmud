inherit "obj/monster";

object carrying;
int i;

reset(arg) {
	::reset(arg);
	if (arg) 
           return;
	set_name("worker");
	set_alias("plant worker");
	set_short("A power plant worker");
	long_desc = "You are looking at one of the many hard working "+
		    "employees who work for Charles Montgomery Burns "+
		    "at the Springfield nuclear power plant.  He "+
		    "obviously has taken the management slogan : "+
		    "'You will always be here' to heart.  He must "+
		    "really care about his job.  You feel inclined "+
		    "to put him out of his misery.\n";
	set_long(format(long_desc, 75));
	set_level(19);
	set_hp(400+random(200));
	set_wc(18);
	set_ac(13);
	i = random(100);
	if (i < 50)
	   carrying = clone_object("players/gowron/room/obj/donut");
	else {
	   carrying = clone_object("obj/money");
	   carrying->set_money(1800+random(500));
	}
	move_object(carrying, this_object());
}

