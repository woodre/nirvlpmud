#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{	
	if(PO->query_suspend())
	{
		write(RED+"Adroushan"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_FIRE() < 1)
	{
		write(RED+"Adroushan"+NORM+" growls: You don't know that spell yet, "+User->query_race()+".\n");
		return 1;
	}
	
	if(User->query_sp() < 60){
		write(RED+"Adroushan"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(PO->query_firebond())
	{
		write(RED+"Adroushan"+NORM+" says: You are already focused and drawing from my strength.\n");
		return 1;
	}
	
	PO->start_firebond();
	PO->set_firebond(1);
	write("\n\nYou trace a symbol of the Element of "+RED+"Fire"+NORM+" on the ground....\nYou begin focusing on "+RED+"Adroushan"+NORM+"....\n");
	write("You start to flow smoothly with the dancing flames....\nAs you perform an ancient kata you start to focus your "+RED+"Fire"+NORM+" abilities.\nYou feel a surge of power rush through your veins.\n\n");
	User->add_spell_point(-60);
	return 1;
}