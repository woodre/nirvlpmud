/*
 * LOCATE command: locate a player, like who2 but less spam
 * By Balowski
 */
#pragma strict_types
#include "../std.h"
#include "../macros.h"
inherit CMD;

status
main(string arg)
{
    object ob;
    
    if (!arg) {
	notify_fail("Locate who?\n");
	return 0;
    }
    if(!(ob = find_player(arg)) || inwizible(ob) || ob->query_invis()) {
	write("Could not locate " + arg + ".\n");
	return 1;
    }
    if (!environment(ob)) {
	write(ob->query_name() + " is nowhere.\n");
	return 1;
    }
    arg = ((string) environment(ob)->short() || "the unknown");
    write(ob->query_name() + " : " + arg + "\n");
    return 1;
}
