#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{	
	if(str) return 0;

        if(!PO->query_bravery()) return 0; 
	
	if(PO->query_brave()) {
		write("You will now lead all fights.\n");
		PO->toggle_brave(); PO->save_me(); return 1; }
		write("You will no longer lead all fights.\n");
		PO->toggle_brave(); PO->save_me(); return 1; }
