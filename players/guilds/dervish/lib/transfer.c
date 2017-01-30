#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	if(User->query_level() < 7) {
		write("You are not advanced enough to do this.\n");
		return 1;
	}
	
	if(PO->query_transfer()) {
		write("Sand transference rescinded.\n");
		PO->set_transfer(0);
		PO->save_me();
		return 1;
	}
	write(BOLD+"You pray to the Sands for energy transference.\n"+OFF);
	PO->set_transfer(1);
	PO->save_me();
	return 1;
}