#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object person, gob;
	string pre;

	if((string)User->query_real_name() != "wicket" && (string)User->query_real_name() != "shinshi")
	{
		write("You do not have permission to do this.\n");
		return 1;
	}
	
	if(PO->query_suspend())
	{
		write("You are suspended and cannot do that.\n");
		return 1;
	}
	
	
	if(!str)
	{
		write("Who are we making a guild wizard?\n");
		return 1;
	}
	
	person = find_living(str);
	gob = present("wicket_element_orb", person);
	
	if(!gob)
	{
		write("That person is not an Elementalist!\n");
		return 1;
	}
	
	if(!gob->query_gwiz())
	{
		write(person->query_name()+" isn't a Guild Wizard for the Elementalists!\n");
		return 1;
	}
	
	pre = "";
  	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;
  	pre += person->query_name()+" is no longer a Guild Wizard!\n";
  	
	gob->set_gwiz(0);
	write("You have removed "+person->query_name()+" as a Guild Wizard.\n");
	tell_object(person, "\n"+User->query_name()+" has removed you as a Guild Wizard of the Elementalists.\n\n");
	CHAND->transmit_message(CHAN_NAME, pre);
	command("gsave", person);
	return 1;	
}