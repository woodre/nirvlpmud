/*
 * Shardak guild, (tm) Dragnar/John
 * tag / untag / inventory is (c) Balowski/Rasmus, 950131
 * set the tag attribute for a given object
 */
#pragma strict_types
#define do_tag(ob) add_attribute("*", ob)
#include "../std.h"
inherit CMD;

status
main(string what)
{
    object ob;

    if (!what) {
	notify_fail( "What do want to tag?\n");
	return 0;
    }

    ob= present( what, this_player());
    if (!ob)
	write( "You do not have a " + what + ".\n");
    else
    {
	do_tag(ob);
        write("You tag " + what + ".\n");
    }

    return 1;
}
