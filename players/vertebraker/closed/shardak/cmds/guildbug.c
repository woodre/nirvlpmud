/*
 * GUILDBUG command. Report guild related bugs
 * By Dragnar and Balowski
 */
#pragma strict_types
#include "../people.h"
#include "../def.h"
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    if (!arg) {
	if (interactive(this_player()) &&
	    member_array(this_player()->query_real_name(), GWIZ) >= 0)
	{
	    write("The latest reported bugs are:\n");
	    tail(LOGDIR + "bugs");
	}
	else
	    write("You must give a short description of the bug.\n");
    }
    else {
	write_file(LOGDIR + "bugs",
		pad((string) this_player()->query_name(), 10) +
		ctime()[4..15] + " : " + arg + "\n");
	write("Thank you.\n");
    }
    return 1;
}
