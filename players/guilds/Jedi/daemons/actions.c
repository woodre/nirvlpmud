#include "../defs.h"

static mapping  cmds, spells;

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
    }

    /*
     * Prepare the spells mapping
     * The spells are bound to the .c files in CMDDIR
     */
    i = sizeof(f = get_dir(SPELLDIR + "*.c"));
    if( i < 10 ) write_file(ERROR, ctime(time())+" Sizeof SPELLDIR files is: "+i+".\n");
    spells = ([ ]);
    
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
        spells += ([ cmd : SPELLDIR + cmd ]);
    }
}

mapping
query_cmds() {

  if(!cmds || sizeof(m_indices(cmds)) < 10) GetActions();
    return cmds;
}


mapping
query_spells() {

  if(!spells || sizeof(m_indices(spells)) < 10) GetActions();
    return spells;
}

void
rehash()
{
  GetActions();
}

