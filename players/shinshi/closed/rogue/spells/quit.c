#include "../defs.h"

status main(string str, object PO, object User)
{
	command("rsave", User);
	CHAND->remove_channel(CHAN_NAME, User);
	User->do_quit();
	return 1;
}