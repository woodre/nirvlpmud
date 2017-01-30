#include <ansi.h>

status main(string str, object PO, object User)
{	
        if (PO->query_stealthed() == 0) {
		write("You are not stealthed.\n");
		return 1;
	}
        write("You leave the safety of the "+HIBLK+"shadows"+NORM+".\n");
        User->unset_invs_sp();
        PO->set_stealthed(0);
        return 1;
}	