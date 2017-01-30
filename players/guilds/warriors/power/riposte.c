/*  Riposte Toggle  */

#include "/players/guilds/warriors/sdefine.h"


main(string str, object gob, object player)
{
	if(!GOB->query_riposte()){
		tell_object(USER,
			"You will now attempt to Riposte while attacked.\n");
		GOB->set_riposte(1);
		return 1;
	}
	else{
		tell_object(USER,
			"You will no longer attempt to Riposte while attacked.\n");
		GOB->set_riposte(0);
		return 1;
	}
	return 1;
}


