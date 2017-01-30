#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object ob, gobj;
	
	PO->h_save();
	
	ob = clone_object(GOB);
	gobj = present(GID, User);
	
	destruct(gobj);
	move_object(ob, User);
	write("You rub your staff and make it look new.\n");
	return 1;
}