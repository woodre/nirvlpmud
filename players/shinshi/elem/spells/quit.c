#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	command("gsave", User);
	CHAND->remove_channel(CHAN_NAME, User);
	User->do_quit();
	return 1;
}