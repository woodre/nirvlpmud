#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object person, gob;
	string pre;

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
		write("Who are we unsuspending?\n");
		return 1;
	}
	
	person = find_living(str);
	gob = present("wicket_element_orb", person);
	
	if(!gob)
	{
		write("That person is not an Elementalist!\n");
		return 1;
	}
	
	if(gob->query_gwiz())
	{
		write("A guild wizard cannot be suspended and therefore does\n");
		write("not need to be unsuspended.\n");
		return 1;
	}
	
	if(!gob->query_suspend())
	{
		write("That person is not suspended.\n");
		return 1;
	}
	
	pre = "";
  	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;
  	pre += person->query_name()+" has been unsuspended by "+User->query_name()+"!\n";
	
	gob->set_suspend(0);
	CHAND->transmit_message(CHAN_NAME, pre);
	write("You have unsuspended "+User->query_name()+".\n");
	tell_object(person, User->query_name()+" has removed your suspension.\n");
	command("gsave", person);
	return 1;	
}