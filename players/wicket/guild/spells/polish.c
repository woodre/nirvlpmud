#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object ob, gobj;
	
       PO->gsave();

	ob = clone_object(GOB);
	gobj = present(GID, User);
	
	destruct(gobj);
	move_object(ob, User);
	write(HIK+"You clean and polish your orb as it shines like new...\n"+NORM);
	return 1;
}
