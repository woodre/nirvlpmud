#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object ob, gob;
	string pre;
	
	if(!PO->query_gwiz())
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
		write("Who are we making an elder?\n");
		return 1;
	}
	
	if(User->query_level() < 40)
	{
		write("You don't have access to do this.\n");
		return 1;
	}
	
	ob = find_living(str);
	
	if(!ob)
	{
		write("Not here. Try again.\n");
		return 1;
	}
	
	gob = present("wicket_element_orb", ob);
	
	if(!gob)
	{
		write("Wanna try again on a REAL Elementalist?\n");
		return 1;
	}
	
	pre = "";
  	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;
  	pre += ob->query_name()+" has been promoted to an Elder!\n";
	
	if(gob)
	{
		if(gob->query_elder())
		{
			write(ob->query_name()+" is already an elder.\n");
			return 1;
		}
		
		if(!gob->query_elder())
		{
			CHAND->transmit_message(CHAN_NAME, pre);
			gob->add_elder(1);
			write("You have made "+ob->query_name()+" an elder.\n");
			tell_object(ob, "\n\n"+User->query_name()+" has made you an elder.\n\n");
			command("gsave", ob);
			return 1;
		}
	}
	return 1;
}