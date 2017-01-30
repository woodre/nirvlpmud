/*
 * ReHaSH for the Shardak guild. (guild wizard command)
 * Call the actions daemon to build actions mapping again
 */
#pragma strict_types
#include "../def.h"
#include "../daemons.h"
#include "../std.h"
inherit CMD;

status
main()
{
    object *marks;
    int i;

    if (this_player()->query_level() < 21) {
	return 0;
    }
    write("Rehashing commands.\n");
    ACTIOND->rehash();
    i = sizeof(marks = (object *) CHANNELD->users("Servants"));
    while (i--) {
	if (marks[i] && environment(marks[i])) {
	    move_object(marks[i], environment(marks[i]));
	}
    }
    return 1;
}
