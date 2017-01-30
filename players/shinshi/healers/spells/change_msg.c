#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	if(!str)
	{
		PO->set_msg("has entered the game.\n");
		write("Your entry message is now: "+User->query_name()+" has entered the game.\n");
		PO->hsave();
		return 1;
	}
	
	if(str)
	{
		PO->set_msg(str);
		write("Your entry message is now: "+User->query_name()+" "+str+".\n");
		PO->hsave();
		return 1;
	}
	return 1;
}