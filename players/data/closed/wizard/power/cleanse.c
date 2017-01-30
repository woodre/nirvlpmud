/*  Cleanse   - Removes Poison for 20 sps & 20 end */

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
	object poison, next;
	string a,b;
	if(USER->query_ghost()) return 0;
	if(USER->query_sp() < 20 || GOB->query_end() < 20){
		tell_object(USER, "You are too weak to do that.\n");
		return 1;
    	}
	tell_object(USER,
   "You concentrate on cleansing your body of toxins...\n");	
	poison = first_inventory(USER);
	while (poison) {
		next = next_inventory(poison);
		if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
			poison->id("poison")) {
			tell_object(USER,
			HIG+"Poison is destroyed"+NORM+BOLD+"..."+NORM+"\n");
			destruct(poison);
		}
		poison = next;
	}
	USER->add_spell_point(-20);
   GOB->add_end(-20);
	return 1;
}


