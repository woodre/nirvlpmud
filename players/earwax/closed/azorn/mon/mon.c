/*
 *      File:                   /players/earwax/closed/azorn/mon/mon.c
 *      Function:               Monster inherit for Azorn quest area
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax
 *                                      All Rights Reserved.
 *      Source:                 10/21/05
 *      Notes:                  
 *      Change History:
 */

#include "../defs.h"
inherit "/obj/monster.c"; 

int laugh_at_evil(object att) {
	tell_room(environment(att), 
	  short()+" laughs at the attempt to damage him with evil!\n");
	return 0;
}

int hurt_from_good(object att) {
	tell_room(environment(att), 
	  short()+" screams in pain from the "+HIW+"holy energies!\n"+NORM);
	return 0;
}

void init() {
	object ob;

	::init();
		
	if (!this_player() || query_attack() || (status)this_player()->is_npc()
	  || !environment() || !environment(this_player())) 
	  return;

	ob = present(ROBES_ID, this_player());
	
	if (!ob || (status)ob->query_worn() < 1)
	{	  
	  tell_room(environment(this_object()), 
	    short()+ " bellows in rage and attacks the intruder "
		  + (string)this_player()->query_name() + ".\n" +NORM);
		attack_object(this_player());
	}
	else
	{
		tell_room(environment(this_object()),
		  short()+ " nods in greeting to "
		  + (string)this_player()->query_name());
	}
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
