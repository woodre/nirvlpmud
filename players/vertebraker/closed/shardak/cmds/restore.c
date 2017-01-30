/*
 * RESTORE command fetches guild statistics
 */
#pragma strict_types
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    if (arg != "guild") return (notify_fail("Restore what?\n"), 0);
    write("Restoring guild stats...\n");
    if (!previous_object()->restore_me()) write("Failed!\n");
    return 1;
}
