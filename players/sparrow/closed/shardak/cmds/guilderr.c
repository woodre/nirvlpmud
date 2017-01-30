/*
 * GUILDERR command. Guild wizards can view/report internal changes
 * By Balowski 30 Sept '95
 */
#pragma strict_types
#include "../people.h"
#include "../def.h"
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    if (!interactive(this_player()) ||
	member_array(this_player()->query_real_name(), GWIZ) == -1)
	return 0;

    if (!arg) {
	write("The latest for-gwiz-eyes-only changes:\n");
	tail(LOGDIR + "changes");
    }
    else {
	write_file(LOGDIR + "changes",
		ctime()[4..15] +
		" (by " + this_player()->query_real_name() +
		") :\n\t" + arg + "\n\n");
	write("Good job!\n");
    }
    return 1;
}
