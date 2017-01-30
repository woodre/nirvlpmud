/*  Hide  */

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
	object ob;
	if(USER->query_ghost()) return 0;
	if(USER->query_sp() < 50){
		tell_object(USER, "You are too weak to perform this.\n");
		return 1;
	}
	if(USER->query_attack()){
		tell_object(USER, "You cannot do this while fighting!\n");
		return 1;
	}
	ob = environment(USER);
	ob = first_inventory(ob);
	while(ob) {
		if (ob != USER && living(ob)) {
			tell_object(USER, 
				"There is someone present, how can you hide?\n");
			return 1;
		}
		ob = next_inventory(ob);
	}
	tell_object(USER, HIW+"You slip into the shadows...\n"+NORM);
	this_player()->set_invs_sp();
	USER->add_spell_point(-50);
	GOB->add_end(-20);
	return 1;
}


