#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object shade, gob;
	int experience;
	
	shade = present("heal_no_xp", User);
	gob = present("new_healers", User);
	
  	User->set_guild_exp(0);
  	User->set_guild_rank(0);
  	User->set_guild_name(0);
  	User->set_guild_file(0);
  	User->set_home(0);
  	experience = (int)User->query_exp();
  	User->add_xp(-experience);
  	if(shade)	shade->shadow_healer_off();
  	User->save_character();
  	write("You have left the Healers.\nGo in peace.\n");
  	destruct(gob);
  	return 1;
}