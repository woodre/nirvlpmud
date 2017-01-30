/*  Level 1 Control Spell: Cleanse   - Removes Poison for 20 sps */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object poison, next;
	string a,b;
	if(USER->query_ghost()) return 0;
	if(CON < 1) return 0;
if(USER->query_sp() < 50){
		tell_object(USER, COLOR+"You lack the energy to do that."+NORM+"\n");
		return 1;
	}
	tell_object(USER,
	COLOR+"A "+NORM+HIK+"Dark Matter"+BOLD+" Tentacle"+NORM+COLOR+" dives beneath your skin."+NORM+"\n");
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
        USER->add_spell_point(-50);
	return 1;
}


