/*
 * Signs. Balowski@Nirvana
 */
#include "/players/guilds/bards/bard_lib/lib.h"
#pragma strict_types
#pragma save_types
private mapping Signs;          /* things to read */

void create()
{
    Signs = ([ ]);
}

void init()
{
    add_action("cmd_read", "read");
}

status id(string str)
{
    return (Signs[str]);
}

status cmd_read(string str)
{
    string s;

    if (!str || !(s = Signs[str])) {
	notify_fail("Read what?\n");
	return 0;
    }
    if (closurep(s))
	s = funcall(s, str);
    if (stringp(s)) {
	if (s[0] == '/') cat(s);
	else write(s);
    }
    say(this_player()->query_name() + " reads the " + str + ".\n");
    return 1;
}

void set_sign(string id, mixed txt)
{
    if (!Signs)
	Signs = ([ id:txt ]);
    else
	Signs[id] = txt;
}

mixed query_sign(string id)
{
    return Signs[id];
}
