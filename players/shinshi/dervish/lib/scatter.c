#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object ob;
	int num, mult;
	
	ob = present("corpse", environment(User));
	
	if(!ob) ob = present("corpse", User);
	
	if(!ob) {
	notify_fail("There is no corpse present.\n"); return 0; }
	num = (int)ob->heal_value();
	write("You lift the "+ob->short()+" into the air.\n\n");
	say(User->query_name()+" lifts the "+ob->short()+" into the air.\n\n");
	tell_room(environment(User),BOLD+"\tA WHIRLWIND APPEARS BEFORE YOU!\n\n"+OFF);
	tell_room(environment(User),"Sand swirls away...\n");
	destruct(ob);
	if(str && (str == "to the sand" || str == "to the sands")) {
	PO->add_sand_points(num*(random(10)+1));
	write(BOLD+"\nThe Sand receives your sacrifice.\n\n"+OFF); return 1; }
	User->heal_self(num);
	return 1; }