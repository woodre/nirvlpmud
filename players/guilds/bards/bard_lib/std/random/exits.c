#include "/players/guilds/bards/bard_lib/lib.h"
#pragma strict_types
#pragma save_types
private mapping Exits;          /* of format direction:file */

void create()
{
    Exits = ([ ]);
}

/*
 * cmd_move (for old times sake it is named move)
 */
status move(string str)
{
    mixed       exit;

    if (exit = Exits[query_verb()]) {
	if (closurep(exit))
	    exit = funcall(exit, str);
	else if (objectp(exit))
	    exit = (mixed) call_other(exit, query_verb(), str);
	if (intp(exit))
	    return exit;
	if (stringp(exit))
	    this_player()->move_player(query_verb() + "#" + exit);
	return 1;
    }
    notify_fail("You cannot go that way.\n");
    return 0;
}

/*
 * Applied by the driver whenever a living creature enters
 */
void init()
{
    int         i;
    mixed       *ks;
    /* okay, so this isn't pretty.. can't have it all */
    i = sizeof(ks = m_indices(Exits));
    while (i--) add_action("move", ks[i]);
}

/*
 * Room exits, this sucks a little *shrug*
 * Adding and removing exits can be done though, just don't like it
 */
void set_exits(mapping m)
{
    Exits += m;
}

void set_exit(string dir, mixed whereto)
{
    Exits[dir] = whereto;
}

mapping query_exits()
{
    return Exits;
}

/*
 * Funky utility functions
 * MakeNoise will send a message to nearby rooms
 */
varargs int MakeNoise(mixed msg, mixed exit, status load)
{
    int         i;
    mixed       *ks;
    object      ob;
    string      x;

    i = sizeof(ks = m_indices(Exits));
    while (i--) {
	if (stringp(exit) && ks[i] != exit) continue;
	if (pointerp(exit) && member_array(ks[i], exit) < 0) continue;
	if (stringp(x = Exits[ks[i]])) {
	    if (load) call_other(x, "");
	    if (ob = find_object(x)) tell_room(ob, msg);
	}
    }
}
