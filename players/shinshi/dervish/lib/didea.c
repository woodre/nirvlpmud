#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	string msg;

	if(!str) return 0;
	msg = RED+"***"+NORM+" "+this_player()->query_name()+": "+NORM+str+RED+" ***"+NORM;
	write_file(LOGPATH+"/didea.txt", msg+"\n");
	write("Thank you for your feedback.\n");
	return 1;
}