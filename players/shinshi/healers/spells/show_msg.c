#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	string msg;
	
	msg = (string)PO->query_msg();
	
	write("Your entry message is: "+User->query_name()+" "+msg+".\n");
	return 1;
}