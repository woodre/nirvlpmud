/*
 * GUILDFIX command. Guild wizards can report fixed bugs to players
 * By Balowski 30 Sept '95
 */
#pragma strict_types
#include "/players/vertebraker/ansi.h"
#include "../people.h"
#include "../def.h"
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    if (!arg) {
	write("The latest corrections are:\n");
	tail(LOGDIR + "fixes");
	return 1;
    }
    if (interactive(this_player()) &&
	member_array(this_player()->query_real_name(), GWIZ) >= 0)
    {
	write_file(LOGDIR + "fixes",
                ctime()[4..15] + " " + (string)this_player()->query_real_name() + " : " + arg + "\n");

        gwiz_tell(HIR + "(" + NORM + "guildfix" + HIR + ")" + NORM + " " + capitalize((string)this_player()->query_real_name()) + " " + arg + "\n", ({ this_player() }));
	write("Good job!\n");
       return 1;
    }
    return 0;
}
