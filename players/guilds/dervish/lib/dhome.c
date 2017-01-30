#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	string current;
	
	current = (string)User->query_home();
	
	if(current == HALLPATH+"/hall.c") {
		write("You choose to log in at the Church.\n");
		User->set_home("/room/church.c");
		User->save();
		return 1;
	}
	
	write("You choose to log in at the "+BOLD+RED+"SandStorm\n"+OFF+OFF);
	User->set_home(HALLPATH+"/hall.c");
	User->save();
	return 1;
}