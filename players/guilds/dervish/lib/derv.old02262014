#include "../defs.h"
#include <ansi.h>

status main(string str, object PO, object User)
{
	if(!CHATOB) {
		write("The guild line is currently down.\n");
		return 1;
	}
	
	if(!str) {
		PO->dervishes();
		return 1;
	}
	
	CHATOB->tell(str);
	return 1;
}