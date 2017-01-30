inherit "obj/weapon";
reset(arg){
	::reset(arg);
	if(!arg){
	set_name("mace");
	set_class(18);
	set_value(5000);
	set_weight(4);
	set_hit_func(this_object());
	set_short("The mace of Mystof");
	set_long("	As you grasp the weapon to examine it, a ray of\n"+
		 "intense light shoots forth from it, illuminating the \n"+
		 "area around you. You realise quickly that this is a \n"+
		 "weapon for good and to strike evil monsters dead...\n");
	}
	}
weapon_hit(attacker){
