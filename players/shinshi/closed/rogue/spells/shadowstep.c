#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object prevent, didshadowstep, enemy;
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(!str){
		write("Who are you trying to appear behind?\n");
		return 1;
	}
	
	if(User->query_level() < 18){
		write("You are too low of a level!\n");
		return 1;
	}
	
	if(!present(str, environment(User))){
		write(str+" is not present!\n");
		return 1;
	}
	
	enemy = present(str, environment(User));
	
	if(!living(enemy)){
		write("That isn't alive!\n");
		return 1;
	}
	
	if(User->query_sp() < 20){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	if(present("shinshi_stop_ss", User)){
		write("That ability is still on cooldown!\n");
		return 1;
	}
	
	if(present("didshadowstep", User)){
		write("You've already shadowstepped!\n");
		return 1;
	}
	
	prevent = clone_object(OBJPATH+"noss.c");
	move_object(prevent, User);
	prevent->start_it();	
	
	if(!present("didshadowstep", User)){
		didshadowstep = clone_object(OBJPATH+"shadowstep.c");
		move_object(didshadowstep, User);
		didshadowstep->start_it();
		User->add_spell_point(-40);
		write("You disappear into the "+HIBLK+"shadows"+NORM+" and appear behind "+str+".\n");
		/*say("DIDSHADOWSTEP APPLIED!\n");   For Debugging Purposes */
		return 1;
	}
	return 1;
}