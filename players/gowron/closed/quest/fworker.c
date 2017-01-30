inherit "obj/monster";

object ob;
int i;

reset(arg) {
	::reset(arg);
	if (arg) 
           return;
	set_name("worker");
	set_alias("fired");
	set_short("A fired worker");
	set_long("This worker was recently dismissed from his job.  "+
		 "Although he hated his job he is still disgruntled "+	
		 "about it.\n");
	set_level(18);
	set_hp(500+random(300));
	set_wc(25);
	set_ac(15);
	set_al(1);
	i = random(100);
	if (i<50) {
	   ob = clone_object("players/gowron/room/obj/donut");
	}
	else {
	   ob = clone_object("obj/money");
	   ob->set_money(random(2800));
	}
	move_object(ob, this_object());
}

	
