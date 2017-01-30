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
		write("Who are we suspending?\n");
		return 1;
	}
	
	person = find_living(str);
	gob = present("wicket_element_orb", person);
	
	if(!person)
	{
		write("That person is not on at the moment.\n");
		return 1;
	}
	
	if(!gob)
	{
		write("That person is not an Elementalist!\n");
		return 1;
	}
	
	if(gob->query_gwiz())
	{
		write("You cannot suspend a guild wizard!\n");
		return 1;
	}
	
	if(gob->query_suspend())
	{
		write("That person is already suspended.\n");
		return 1;
	}
	
	pre = "";
  	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;
  	pre += person->query_name()+" has been suspended by "+User->query_name()+"!\n";
	
	gob->set_suspend(1);
	CHAND->transmit_message(CHAN_NAME, pre);
	write("You have suspended "+person->query_name()+" until further notice.\n");
	tell_object(person, "You have been suspended by "+User->query_name()+" until further notice.\n");
	command("gsave", person);
	return 1;	
}