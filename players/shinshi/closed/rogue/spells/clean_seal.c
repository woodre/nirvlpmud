#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object ob, gob;
	
	ob = clone_object(MAINPATH+"gob2.c");
	gob = present("shinshi_rogue_seal", User);
	
	destruct(gob);
	move_object(ob, User);
	write(HIK+"Updating guild object...\n"+NORM);
	return 1;
}