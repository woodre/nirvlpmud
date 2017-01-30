#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object shinshi;
	
	if(!str)
	{
		write("You have to say something!\n");
		return 1;
	}
	
	shinshi = find_player("shinshi");
	
	if(!shinshi){
		write_file(LOGPATH+"RIDEA", ctime()[4..15] + "  " +User->query_name()+ " says: "+str+".\n");
		write("Thank you for your input! -Shinshi\n");
	}
	else{
		tell_object(shinshi, RED+"(XX "+NORM+"RIDEA"+RED+" XX) "+NORM+User->query_name()+" says: "+str+".\n");
		write_file(LOGPATH+"RIDEA", ctime()[4..15] + "  " +User->query_name()+ " says: "+str+".\n");
		write("Thank you for your input! -Shinshi\n");
	}
	return 1;
}