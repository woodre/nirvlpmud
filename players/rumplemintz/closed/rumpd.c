#include "defs.h"
inherit "/players/rumplemintz/closed/sefun.c";

/* Globals */
string *cmdlist;

/* Prototypes */
int initialize_commands();

void
reset(status arg)
{
    if (arg)
        return;
        
    initialize_commands();
}

int
initialize_commands()
{
    object rump;
    
    rump = find_player("rumplemintz");
    if (!rump)
    {
        cmdlist = ({ });
        return 1;
    }
    
    cmdlist = query_actions(rump);
    tell_object(rump,"SIZE is " + sizeof(cmdlist) + "\n");
    return 1;
}
