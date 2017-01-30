#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	if(PO->query_suspend())
	{
		write(YEL+"Aeolos"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
		
	if(PO->query_AIR() < 7){
		write(YEL+"Aeolos"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 50){
		write(YEL+"Aeolos"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(PO->query_airshroud())
	{
		write(YEL+"Aeolos"+NORM+" says: You are not yet ready to do this again!\n");
		return 1;
	}
	
	PO->start_airshroudCD();
	PO->start_airshroudLength();
	PO->set_airshroud(1);
	PO->set_niggerrig2(0);
	write(BOLD+"\nYou thrust your palm towards the sky as you draw strength from "+NORM+YEL+"Aeolos"+NORM+BOLD+"...\n"+NORM+BOLD+"Winds funnel down from the clouds surrounding you as you speed up."+NORM+"\n");
	say(BOLD+User->query_name()+" thrusts "+User->query_possessive()+" palm towards the sky drawing strength from "+NORM+YEL+"Aeolos"+NORM+BOLD+".....\n"+BOLD+"Winds funnel down from  the clouds surrounding them as they speed up.\n"+NORM);
	User->add_spell_point(-50);
	return 1;
}