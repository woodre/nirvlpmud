#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object corpse;
	int earth, fire, water, air, heal;
	
	if(PO->query_suspend())
	{
		write("You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost()) return 0;

	corpse = present("corpse", environment(User));
	
	if(!corpse)
	{
		write("There is no corpse here.\n");
		return 1;
	}
	
	earth = (int)PO->query_earthbond();
	fire = (int)PO->query_firebond();
	water = (int)PO->query_waterbond();
	air = (int)PO->query_airbond();
	
	if(corpse)
	{
		if(earth && fire && water && air)
		{
			heal = (int)corpse->heal_value();
			heal *= 2;
			write("You drain the essence of the corpse.\n");
			say(User->query_name()+" drains the essence of the corpse.\n");
			User->heal_self(heal);
			destruct(corpse);
			return 1;
		}
		
		else
		{
			heal = (int)corpse->heal_value();
			write("You drain the essence of the corpse.\n");
			say(User->query_name()+" drains the essence of the corpse.\n");
			User->heal_self(heal);
			destruct(corpse);
			return 1;
		}
		return 1;
	}
	return 1;
}