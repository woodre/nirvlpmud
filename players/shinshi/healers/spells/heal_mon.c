#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	if(!PO->query_mon_on())
	{
		write("You turn on the Heal Monitor.\n");
		PO->set_mon_on(1);
		return 1;
	}
	
	if(PO->query_mon_on())
	{
		write("You turn off the Heal Monitor.\n");
		PO->set_mon_on(0);
		return 1;
	}
	return 1;
}