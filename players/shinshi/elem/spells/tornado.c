#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object player;
	string location;
	
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
	
	if(User->query_sp() < 75)
	{
		write(YEL+"Aeolos"+NORM+" says: You do not have the magical energies needed.\n");
		return 1;
	}
	
	if(!str)
	{
		write("You pray to "+YEL+"Aeolos"+NORM+".\nA large "+WHT+"tornado"+NORM+" appears...\n");
		write("A funnel comes down from the clouds....\nYou are swept into the "+WHT+"tornado"+NORM+"...\n");
		write("The "+WHT+"tornado"+NORM+" release you on the ground...\nEverything clears and you are now in the Guildhall.\n");
		say(User->query_name()+" prays to "+YEL+"Aeolos"+NORM+".\nA large "+WHT+"tornado"+NORM+" appears...\n");
		say("A funnel comes down from the clouds...\n"+User->query_name()+" is swept into the "+NORM+"tornado"+NORM+"...\n");
		say("The "+WHT+"tornado"+NORM+" disappears from sight.\n");
		User->add_spell_point(-75);
		User->move_player("through a tornado#/players/wicket/guild/hall/rooms/entrance.c");
		return 1;
	}
	
	if(str)
	{
		player = find_player(str);
		
		if(!player)
		{
			write(YEL+"Aeolos"+NORM+" says: That player is not currently logged in.\n");
			return 1;
		}
		
		if(!present("wicket_element_orb", player))
		{
			write(YEL+"Aeolos"+NORM+" says: You can only teleport to fellow "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ists"+NORM+".\n");
			return 1;
		}
		
		if(present("wicket_element_orb", player))
		{
			if((string)User->realm() == "NT")
			{
				write(YEL+"\nAeolos"+NORM+" says, \"My winds cannot carry you away from this location at this time.\"\n");
				return 1;
			}
			
			if((string)environment(player)->realm() == "NT")
			{
				write(YEL+"\nAeolos"+NORM+" says, \"My winds cannot carry you to that location at this time.\"\n");
				return 1;
			}
			
			else
			{
				location = file_name(environment(player));
				 write("You pray to "+YEL+"Aeolos"+NORM+".\nA large "+WHT+"tornado"+NORM+" appears...\n");
		         write("A funnel comes down from the clouds....\nYou are swept into the "+WHT+"tornado"+NORM+"...\n");
		         write("The "+WHT+"tornado"+NORM+" releases you onto the ground...\nEverything clears and "+player->query_name()+" stands next to you.\n");
		         say(User->query_name()+" prays to "+YEL+"Aeolos"+NORM+".\nA large "+WHT+"tornado"+NORM+" appears...\n");
		         say("A funnel comes down from the clouds...\n"+User->query_name()+" is swept into the "+WHT+"tornado"+NORM+"...\n");
		         say("The "+WHT+"tornado"+NORM+" disappears from sight.\n");
		         User->add_spell_point(-75);
				move_object(User, location);
				return 1;
			}
			return 1;
		}
		return 1;
	}
	return 1;
}