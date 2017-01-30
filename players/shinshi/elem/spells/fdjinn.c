#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object djinn;
	
	if(PO->query_suspend())
	{
		write(RED+"Adroushan"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_FIRE() < 5)
	{
		write(RED+"Adroushan"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 100)
	{
		write(RED+"Adroushan"+NORM+" growls: You do not have the magical energies needed to do this, "+User->query_race()+"!\n");
		return 1;
	}
	
	if(PO->query_has_djinn())
	{
		write(RED+"Adroushan"+NORM+" says: Your Djinn is already with you!\n");
		return 1;
	}
	
	if(FIREDAEMON->check_people(User))
	{
		write(RED+"Adroushan"+NORM+" says: You have already summoned your "+RED+"Fire Djinn"+NORM+" today!\n");
		return 1;
	}
	
	if(!PO->query_firebond())
	{
		write("\n\nYou call upon "+RED+"Adroushan"+NORM+" for aid in combat...\n\n"+RED+"Embers"+NORM+" whip around the room.....\n\nAn Ancient "+RED+"Fire Djinn"+NORM+" appears by your side and bows to you.\n\n"+NORM);
		say(User->query_name()+" calls upon "+RED+"Adroushan"+NORM+" for aid to come and assist "+User->query_objective()+".\n");
		User->add_spell_point(-100);
		move_object(clone_object(DJINNPATH+"fdjinn.c"), environment(User));
		djinn = present("djinn", environment(User));
		djinn->patch_owner(this_player());
    	djinn->set_level(9);
    	djinn->set_ac(10);
    	djinn->set_wc(10);
    	djinn->set_hp(175);
    	djinn->init();
    	PO->set_has_djinn(1);
    	FIREDAEMON->add_people(User);
	}
	
	else
	{
		write("\n\nAn Ancient "+RED+"Fire Djinn"+NORM+" appears and bows..\n\n"+NORM);
		say(User->query_name()+" calls upon "+RED+"Adroushan"+NORM+" for aid to come and assist "+User->query_objective()+".\n");
		User->add_spell_point(-100);
		move_object(clone_object(DJINNPATH+"fdjinn.c"), environment(User));
		djinn = present("djinn", environment(User));
		djinn->patch_owner(this_player());
    	djinn->set_level(9);
    	djinn->set_ac(20);
    	djinn->set_wc(20);
    	djinn->set_hp(350);
    	djinn->init();
    	PO->set_has_djinn(1);
    	FIREDAEMON->add_people(User);
		return 1;
	}
	return 1;
}