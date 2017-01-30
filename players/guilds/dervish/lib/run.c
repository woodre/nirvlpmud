#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	string c1, c2, c3, c4, c5;            
	string complete;
	
	if(!str) {
		write("Where would you like to run to?\n");
		return 1;
	}
	complete = BOLD+"~ ~ ~ RUN  ENDED ~ ~ ~"+OFF+"\n";
	write(BOLD+"~ ~ ~ RUNNING ~ ~ ~\n\n"+OFF);
	if(sscanf(str,"%s,%s,%s,%s,%s", c1, c2, c3, c4, c5) == 5) {
		PO->ncom(c1); PO->ncom(c2); PO->ncom(c3); PO->ncom(c4); PO->ncom(c5);
		write(complete);
		return 1;
	}
	
	if(sscanf(str, "%s,%s,%s,%s", c1, c2, c3, c4) == 4) {
		PO->ncom(c1); PO->ncom(c2); PO->ncom(c3); PO->ncom(c4);              
		write(complete);
		return 1;
	}
	
	if(sscanf(str, "%s,%s,%s", c1, c2, c3) == 3) {
		PO->ncom(c1); PO->ncom(c2); PO->ncom(c3); 
		write(complete);
		return 1;
	}
	
	if(sscanf(str,"%s,%s", c1, c2) == 2) {
		PO->ncom(c1); PO->ncom(c2);
		write(complete);
		return 1;
	}
	
	if(sscanf(str, "%s", c1) == 1) {
		command(c1, User);
		write(complete);
		return 1;
	}
	return 1;
}