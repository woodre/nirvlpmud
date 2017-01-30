#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	if(PO->query_suspend())
	{
		write(GRN+"Aatami"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_EARTH() < 1)
    {
    	write(GRN+"Aatami"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
    	return 1;
    }
		
	if(User->query_sp() < 60){
		write(GRN+"Aatami"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(PO->query_earthbond())
	{
		write(GRN+"Aatami"+NORM+" says: You are already focused and drawing from my strength.\n");
		return 1;
	}
	
	PO->start_earthbond();
	PO->set_earthbond(1);
	write("\n\nYou trace a symbol of the Element of "+GRN+"Earth"+NORM+" on the ground....\nYou begin focusing on "+GRN+"Aatami"+NORM+"....\n");
	write("You start to earth rumble under your feet....\nAs you perform an ancient kata you start to focus your "+GRN+"Earth"+NORM+" abilities.\nYou feel a surge of power rush through your veins.\n\n");
	User->add_spell_point(-60);
	return 1;
}