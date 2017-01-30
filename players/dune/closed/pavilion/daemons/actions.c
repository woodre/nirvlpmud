/*
 * Actions daemon is (c) Balowski/Rasmus, Late April 1995.
 * The mapping is used in a "command hook" construct
 * Since the mapping is equal for all, why not put it here? :)
 */
#include "../DEFS.h"

static mapping  cmds;           /* [command : file] - list
				 * it is shared, so don't do anything
				 * foolish with it
				 */

void
reset(int arg)
{
    int         i;
    string      *f, cmd;

    if (arg) return;

    /*
     * Prepare the cmds mapping
     * The commands are bound to the .c files in BINDIR
     */
    i = sizeof(f = files(CMDDIR + "*.c"));
    cmds = allocate_mapping(i);
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	cmds[cmd] = CMDDIR + cmd;
    }
}

mapping
query_cmds()
{
    /*
     * Just return the mapping, share share share!
     */
    return cmds;
}

void
rehash()
{
    int         i;
    string      *f, cmd;

    /*
     * Add any new commands to the shared mapping
     */
    i = sizeof( f = files( CMDDIR + "*.c"));
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	cmds[cmd] = CMDDIR + f[i];
    }
}
