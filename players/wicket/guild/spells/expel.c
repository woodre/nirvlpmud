#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object player, gob;
	string who, why, pre;
	
	if(!PO->query_elder() && !PO->query_gwiz())
	{
		return 0;
	}
	
	if(PO->query_suspend())
	{
		write("You are suspended and cannot do that.\n");
		return 1;
	}
	
	if(!str)
	{
		write("Who are we expelling from the guild?\n");
		return 1;
	}
	
	if(sscanf(str, "%s %s", who, why) != 2)
	{
		write("Usage: expel 'player' 'reason'\n");
		return 1;
	}
	
	player = find_player(who);
	gob = present("wicket_element_orb", player);
	
	if(!gob)
	{
		write("That player is not an Elementalist.\n");
		return 1;
	}
	
	if(gob->query_elder() && PO->query_elder())
	{
		write("You cannot expel other Elders!\n");
		return 1;
	}
	
	if(gob->query_gwiz() && PO->query_elder())
	{
		write("You cannot expel a GUILD WIZARD!\n");
		return 1;
	}
	
	if(gob->query_gwiz() && (PO->query_gwiz() && (string)User->query_real_name() != "wicket") && (PO->query_wiz() && (string)User->query_real_name() != "shinshi"))
	{
		write("You cannot do that.\n");
		return 1;
	}
	
	pre = "";
  	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;
  	pre += player->query_name()+" has been removed from the guild by "+User->query_name()+"!\n";
	
	write("You expel "+player->query_name()+" from the guild.\n");
	gob->set_reason(why);
	command("gsave", player);
	CHAND->transmit_message(CHAN_NAME, pre);
	destruct(gob);
	CHAND->remove_channel(CHAN_NAME, player);
	player->set_guild_name(0);
	player->set_guild_file(0);
	player->set_guild_exp(0);
	player->set_guild_rank(0);
	tell_object(player, "You have been removed from the guild.\n");
	tell_object(player, "Reason: "+why+".\n");
	return 1;
}