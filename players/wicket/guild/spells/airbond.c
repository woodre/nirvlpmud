#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	if(PO->query_suspend())
	{
		write(YEL+"Aeolos"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_AIR() < 1)
	{
		write(YEL+"Aeolos"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 60){
		write(YEL+"Aeolos"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(PO->query_airbond())
	{
		write(YEL+"Aeolos"+NORM+" says: You are already focused and drawing from my strength.\n");
		return 1;
	}
	
	PO->start_airbond();
	PO->set_airbond(1);
	write("\n\nYou trace a symbol of the Element of "+YEL+"Air"+NORM+" on the ground....\nYou begin focusing on "+YEL+"Aeolos"+NORM+"....\n");
	write("You start to flow smoothly with the winds....\nAs you perform an ancient kata, you start to focus your "+YEL+"Air"+NORM+" abilities.\nYou feel a surge of power rush through your veins.\n\n");
	User->add_spell_point(-60);
	return 1;
}