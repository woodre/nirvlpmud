#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	string msg;
	
	if(!str) return 0;
	
	msg = RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+NORM+": "+User->query_name()+" says: "+str;
	
	write_file(LOGPATH+"etypo.txt", msg+"\n");
	write("Thank you for your typo find!\n");
	return 1;
}