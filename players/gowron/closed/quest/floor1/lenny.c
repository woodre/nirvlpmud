inherit "obj/monster";

reset(arg) {
	monster::reset(arg);
	if (arg)
	   return;
	set_name("lenny");
	set_alias("worker");
	set_short("Lenny");
	set_long("This is Lenny, a friend and co-worker of Homer Simpson.\n");
	set_level(15);
	set_wc(16);
	set_ac(8);
	set_hp(300);
	set_al(10);
}
