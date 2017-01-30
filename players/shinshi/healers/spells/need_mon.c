#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	if(!PO->query_monitor())
	{
		write("You turn on the Need Monitor.\n");
		PO->set_monitor(1);
		return 1;
	}
	
	if(PO->query_monitor())
	{
		write("You turn off the Need Monitor.\n");
		PO->set_monitor(0);
		return 1;
	}
	return 1;
}