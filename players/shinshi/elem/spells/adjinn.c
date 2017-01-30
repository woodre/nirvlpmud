#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object djinn;
	
	if(PO->query_suspend())
	{
		write(YEL+"Aeolos"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_AIR() < 5)
	{
		write(YEL+"Aeolos"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 100)
	{
		write(YEL+"Aeolos"+NORM+" says: You do not have the magical energies needed to do this!\n");
		return 1;
	}
	
	if(PO->query_has_djinn())
	{
		write(YEL+"Aeolos"+NORM+" says: Your Djinn is already with you.\n");
		return 1;
	}
	
	if(AIRDAEMON->check_people(User))
	{
		write(YEL+"Aeolos"+NORM+" says: You have already summoned your "+YEL+"Air Djinn"+NORM+" today.\n");
		return 1;
	}
	
	if(!PO->query_airbond())
	{
		write("\n\nYou call upon "+YEL+"Aeolos"+NORM+" for aid in combat...\n\nThe "+YEL+"winds"+NORM+" whip around the room.....\n\nAn Ancient "+YEL+"Air Djinn"+NORM+" appears by your side and bows to you.\n\n"+NORM);
		say(User->query_name()+" calls upon "+YEL+"Aeolos"+NORM+" for aid to come assist "+User->query_objective()+".\n");
		User->add_spell_point(-100);
		move_object(clone_object(DJINNPATH+"adjinn.c"), environment(User));
		djinn = present("djinn", environment(User));
		djinn->patch_owner(this_player());
    	djinn->set_level(9);
    	djinn->set_ac(10);
    	djinn->set_wc(10);
    	djinn->set_hp(175);
    	djinn->init();
    	PO->set_has_djinn(1);
    	AIRDAEMON->add_people(User);
    	return 1;
	}
	
	else
	{
		write("\n\nAn Ancient "+YEL+"Air Djinn"+NORM+" appears and bows to you.\n\n"+NORM);
		say(User->query_name()+" calls upon "+YEL+"Aeolos"+NORM+" for aid to come and assist "+User->query_objective()+".\n");
		User->add_spell_point(-100);
		move_object(clone_object(DJINNPATH+"adjinn.c"), environment(User));
		djinn = present("djinn", environment(User));
		djinn->patch_owner(this_player());
    	djinn->set_level(9);
    	djinn->set_ac(20);
    	djinn->set_wc(20);
    	djinn->set_hp(350);
    	djinn->init();
    	PO->set_has_djinn(1);
    	AIRDAEMON->add_people(User);
		return 1;
	}
	return 1;
}