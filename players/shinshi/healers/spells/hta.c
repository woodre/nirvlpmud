#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	string pre;
	
	if(!CHAND)
	{
		write("The guild line is currently down.\n");
		return 1;
	}
	
	if(!str)
	{
		write("What would you like to echo?\n");
		return 1;
	}
	
	pre = "";
	pre += BLU+"("+RED+"[ "+NORM;
	pre += str;
	pre += " <"+User->query_name()+">\n";
		
	CHAND->transmit_message(CHAN_NAME, pre);
	return 1;
}