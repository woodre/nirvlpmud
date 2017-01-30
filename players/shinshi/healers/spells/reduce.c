#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	if(!PO->query_reduced())
	{
		write("You reduce the Need Monitor.\n");
		PO->set_reduced(1);
		return 1;
	}
	
	if(PO->query_reduced())
	{
		write("You revert to the normal Need Monitor.\n");
		PO->set_reduced(0);
		return 1;
	}
	return 1;
}