#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object gob;
	
	gob = present("orb", User);
	
	if(present("djinn", environment(User)))
	{
		command("dismiss djinn", User);
		gob->set_has_djinn(0);
	}
	
        if(gob->query_has_djinn())
          gob->set_has_djinn(0);
	
	command("gsave", User);
	CHAND->remove_channel(CHAN_NAME, User);
	User->do_quit();
	return 1;
}