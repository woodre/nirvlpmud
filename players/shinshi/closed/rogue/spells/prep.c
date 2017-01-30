#include "../defs.h"

status main(string str, object PO, object User)
{
	object blind, expose, garrote, pp, ss, vanish, prevent;
	
	blind = present("shinshi_no_blind", User);
	expose = present("shinshi_stop_expose", User);
	garrote = present("shinshi_no_garrote", User);
	ss = present("shinshi_stop_ss", User);
	vanish = present("shinshi_stop_vanish", User);
	
	if(User->query_extra_level() < 25)
	{
		write("You cannot use that ability yet!\n");
		return 1;
	}
	
	if(present("shinshi_stop_prep", User)){
		write("You cannot do that so soon!\n");
		return 1;
	}
	
	if(User->query_sp() < 40){
		write("You do not have the energy to do that!\n");
		return 1;
	}
	
	if(blind || expose || garrote || ss || vanish){
		destruct(blind);
		destruct(expose);
		destruct(garrote);
		destruct(ss);
		destruct(vanish);
		write("You prepare for battle and regain all of your abilities.\n");
		prevent = clone_object(OBJPATH+"noprep.c");
		move_object(prevent, User);
		prevent->start_it();
		User->add_spell_point(-40);
		return 1;
	}
	return 1;
}