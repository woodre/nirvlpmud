#include "../defs.h"

static mapping  cmds;

void
GetActions() {
    int         i;
    string      *f, cmd;

    /*
     * Prepare the cmds mapping
     * The commands are bound to the .c files in CMDDIR
     */
    i = sizeof(f = get_dir(CMDDIR + "*.c"));
    if( i < 10 ) write_file(ERROR, ctime(time())+" Sizeof CMDDIR files is: "+i+".\n");
    cmds = ([ ]);
    
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
        cmds += ([ cmd : CMDDIR + cmd ]);
	/* cmds[cmd] = CMDDIR + cmd; */
    }
}

mapping
query_cmds() {

  if(!cmds || MAP->MappingSize(cmds) < 10) GetActions();
    return cmds;
}

void
rehash()
{
  GetActions();
}

