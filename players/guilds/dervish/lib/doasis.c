#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object att, *ob, myob;
	int h, s;
	
	if(this_player()->query_level() < 12) {
	write("You are unable to use this ability yet.\n"); return 1; }
	if(this_player()->query_no_spell() || this_player()->checkNM() || this_player()->query_sp() < 45) {
	write("You are unable to work the sands at this time.\n"); return 1; }
	if(this_player()->query_ghost()) {
	write("You cannot do that while you are dead!\n"); return 1; }
	s = sizeof(ob = all_inventory(environment(TP)));

	while(h < s)
	{
		if(att = (object)ob[h]->query_attack())
		{
			ob[h]->stop_fight();
			att->stop_fight();
			ob[h]->stop_fight();
			att->stop_fight();
		}
		h ++;
	}

	tell_room(environment(TP), 
	capitalize((string)TP->query_name())+" summons a calming oasis of sand into the room.\n");
	this_player()->add_spell_point(-45);
	PO->add_spell_delay(random(10)+1);
	return 1;
}