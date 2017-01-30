inherit "obj/armor";

reset(arg) {
::reset(arg);
	set_short("A ring pop");
	set_long("This is a Ring Pop. It is a plastic ring with a huge jewel\n"+
"shaped candy on it. It can be worn as armor, or eaten.\n");
	set_ac(1);
	set_value(1000);
	set_weight(1);
	set_alias("ring");
	set_name("ring pop");
	set_type("ring");
	}
init() {
  add_action("wear", "wear");
  add_action("remove", "remove");
  add_action("take_off", "unwear");
  add_action("eat", "eat");
}

eat(str) {
	if(!str) return 0;
	if(str!="ring") return 0;

	if(str="ring") {
	write("You pop the ring into your mouth and with a *CRUNCH* it is gone.\n");
	say((this_player()->query_name())+" crunches up a Ring Pop.\n");
	this_player()->heal_self(30);
	destruct(this_object());
	return 1;
	}
return 0;
}
