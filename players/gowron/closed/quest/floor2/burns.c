inherit "obj/monster";

reset(arg) {
	object ob;
	::reset(arg);
	if (arg)
           return;
	set_name("burns");
	set_alias("monty");
	set_short("Monty Burns");
	set_long(format("Charles Montgomery Burns, the owner of this "+
		        "power plant.  He is a frail old man, and "+
			"doesn't look too tough..\n", 75));
	set_level(18);
	set_hp(180);
	set_wc(15);
	set_ac(10);
	set_al(-1000);
	set_chat_chance(15);
	load_chat("Burns says: Excellent..\n");
}
	
