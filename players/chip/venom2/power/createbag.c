/*  Level 4 Creation Spell: createbag - Allows the Symb to make a
bag that can be used to hold a good amount of loot.  Cost is 150 mp +
150 sps.   Forms a bag made of dark matter that they can then shape.*/

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object woot;
	if(USER->query_ghost()) return 0;
	if(CRE < 4) return 0;
	if(GOB->query_mp() < 150){ tell_object(USER, "You are too low on "+HIK+"Dark Matter"+NORM+" to perform that.\n"); return 1; }
	if(USER->query_sp() < 150){ tell_object(USER, "You lack the energy to create a bag.\n"); return 1; }
	USER->add_spell_point(-150);
	GOB->add_mp(-150);
	tell_object(USER,
		"You hold out your hand and concentrate for a moment...\n"+
	"A bag made of "+HIK+"Dark Matter"+NORM+" forms in your upward turned palm.  Look at it to see how to use it.\n");
	tell_room(environment(USER),
	USER->query_name()+" closes "+USER->POS+" eyes and forms a bag made of "+HIK+"Dark Matter"+NORM+" in "+USER->POS+" palm.\n", ({USER}));
	woot = clone_object("/players/chip/venom2/OBJ/deepbag.c");
	woot->set_who(USER->query_real_name());
	move_object(woot, USER);
	return 1;
}
