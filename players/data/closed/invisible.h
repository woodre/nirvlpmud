/*  Hide  */

#include "/players/data/closed/wizard/sdefine.h"


main(string str, object gob, object player)
{
	object ob;
	if(USER->query_ghost()) return 0;
	
	}
    
	
	ob = environment(USER);
	ob = first_inventory(ob);
			}
		ob = next_inventory(ob);
	}
	tell_object(USER, HIW+"You slip into the shadows...\n"+NORM);
	this_player()->set_invs_sp();
		
	return 1;
}


