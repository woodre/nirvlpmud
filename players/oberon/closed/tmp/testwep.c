#include "/obj/ansi.h"
inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_alias("jewel");
	set_type("exotic");
	set_short(""+BOLD+"The Jewel of Judgment"+NORM+"");
	set_long("This is the Legendary Jewel of Judgement.\n");
	set_params("other|good",20,0);
	set_class(100);
	set_weight(1);
	set_value(0);
	set_name(""+BOLD+"Jewel of Judgment"+NORM+"");
	set_min_xlevel(101);
	set_min_xlevel_message("Foolish Moral. Try again when you are more Experienced.\n");
	message_hit = ({
		BOLD+" EVISCERATED "+NORM," Blood gushes everywhere",
		HIR+" HACKED "+NORM," extremely hard",
		HIY+" CHOPPED "+NORM," viciously",
		HIC+" minced "+NORM,", with precision",
		HIG+" sliced "+NORM," drawing a little blood",
		HIB+" struck "+NORM," lightly",
		HIW+" grazed "+NORM," very lightly"
	});
	set_hit_func(this_object());
}

weapon_hit(attacker) {
	say(this_player()->query_name()+" peers into the "+BOLD+"Jewel of Judgement"+NORM+".\n");
	write("You peer into the "+BOLD+"Jewel of Judgement"+NORM+".\n");
	return 1000;
}
