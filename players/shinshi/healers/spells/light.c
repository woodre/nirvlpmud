#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
		
	if(PO->query_lighting())
	{
		write("You dim the light of your staff.\n");
		set_light(-2);
		PO->set_lighting(0);
		return 1;
	}
	
	if(!PO->query_lighting())
	{
		write("You brighten the room with the light of your staff.\n");
		set_light(2);
		PO->set_lighting(1);
		return 1;
	}
	return 1;
}