inherit "obj/weapon";
int die, attacker, pain;

init() {
	add_action("eat","eat");
	add_action("hold","hold");
	}

reset(arg) {
::reset(arg);
        if(!arg) {
		set_name("stick");
		set_class(18);
		set_value(3000);
		set_weight(4);
		set_alias("stick");
	set_short("A purple stick");
set_long(
"	This is a purple stick. It is light, and makes funny noises when you\n"+
"  swing it. Instead of being wielded like a regular weapon, you must 'hold'\n"+
"  it. It looks like you can 'eat' this stick too.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(10) < 3)  {
	write("You thwap your enemy senseless with a daring blow!\n");
	say((this_player()->query_name())+" clobbers the enemy with a strange-looking purple stick!\n");
	return 5;
	}
}

hold(str) {
	if(!str) return 0;
	if(str=="stick") {
	present("stick", this_player())->wield(str);
	return 1;
	}
	return 0;
}
eat(str) {
	object tp;
	tp=this_player();
	if(!str || !id(str))
		return 0;
	if(str == "stick") {

	tp->heal_self(40);
	write("You feel like you have stuck your head in a closing elevator door. Ahhh!\n");
	destruct(this_object());
	return 1;
	}
}
