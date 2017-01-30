/*
 * GSTaT shows various stats for the guild (wizards only)
 * namely users on the channel daemon, and actions in actions daemon
 */
#pragma strict_types
#include "../def.h"
#include "../daemons.h"
#include "../std.h"
inherit CMD;

void
showchan(string chan)
{
    mixed       *us;
    int         i;
    string	s;
    
    s = pad(chan + ":", 12);
    i = sizeof(us = (mixed *) CHANNELD->users(chan));
    while (i--) {
	if (!objectp(us[i])) {
	    s += pad("<empty>", 12);
	}
	else if (interactive(us[i])) {
	    s += pad((string) us[i]->query_name(), 12);
	}
	else if (environment(us[i])) {
	    s += pad((string) environment(us[i])->query_name(), 12);
	}
	else s += pad("<unknown>", 12);
    }
    write(format(s + "\n", 72));
}

status
main(string what)
{
    mapping     cmds;
    mixed       *us;
    int         i;

    if (this_player()->query_level() < 21)
	return 0;

    write("PLaYeRS oN CHaNNeL DaeMoN:\n");
    showchan("Servants");
    showchan("[Servants]");
    showchan("{Servants}");
    
    write("CoMMaNDS iN aCTioNS DaeMoN:\n");
    cmds = (mapping) ACTIOND->query_cmds();
    i = sizeof(us = keys(cmds));
    while (i--) {
	write(us[i] + "\t");
    }
    write("\n");
    return 1;    
}
