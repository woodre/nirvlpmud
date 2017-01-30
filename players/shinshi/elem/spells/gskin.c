#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object skin;
	
	if(PO->query_suspend())
	{
		write(GRN+"Aatami"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_EARTH() < 2){
		write(GRN+"Aatami"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 70){
		write(GRN+"Aatami"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(PO->query_gskin())
	{
		write(GRN+"Aatami"+NORM+" says: You are not yet ready to do this again!\n");
		return 1;
	}
	
	PO->start_gskinCD();
	PO->start_gskinLength();
	PO->set_gskin(1);
	PO->set_niggerrig(0);
	skin = clone_object("/players/wicket/guild/objs/gskin.c");
	move_object(skin, User);
	command("wear wicket_ele_skin", User);
	write(BOLD+"You thrust your palm towards the ground. Granite shards fly up and encase your body, forming a skin of stone.\n"+NORM);
	say(BOLD+User->query_name()+" thrusts "+User->query_possessive()+" palm towards the ground. Granite shards fly up and encase "+User->query_objective()+", forming a skin of stone.\n"+NORM);
	User->add_spell_point(-70);
	return 1;
}