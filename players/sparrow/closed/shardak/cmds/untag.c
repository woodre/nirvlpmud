/*
 * Shardak guild, (tm) Dragnar/John
 * tag / untag / inventory is (c) Balowski/Rasmus, 950131
 * remove the tag attribute from a given object
 */
#pragma strict_types
#define do_untag(ob) delete_attribute("*", ob)
#include "../std.h"
inherit CMD;

status
main(string what)
{
    object ob;

    if (!what) {
	notify_fail( "What do want to untag?\n");
	return 0;
    }

    ob = present( what, this_player());
    if (!ob)
	write( "You do not have a " + what + ".\n");
    else
    {
	do_untag( ob);
      write("You untag " + what + ".\n");
    }

    return 1;
}
