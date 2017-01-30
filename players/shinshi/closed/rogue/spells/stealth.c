#include <ansi.h>

status main(string str, object PO, object User)
{		
	if(User->query_attack()){
		write("You cannot do that in combat!\n");
		return 1;
	}
		
        if ((int)PO->query_stealthed() == 1) {
		write("You are already stealthed!\n");
		return 1;
	}
        write("You conjure "+HIBLK+"shadows"+NORM+" and wrap them about yourself.\n");
        User->set_invs_sp();
        PO->set_stealthed(1);
        return 1;
}