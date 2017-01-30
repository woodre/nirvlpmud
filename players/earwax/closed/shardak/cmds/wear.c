/*
 * WEAR command for the Servants of Shardak (for special armour)
 * (c) Balowski/Rasmus H. Hansen 1996
 */
#pragma strict_types
#include "../std.h"
inherit CMD;

status
main(string str)
{
    object ob, worn;

    if (!str) {
	notify_fail("Wear what?\n");
	return 0;
    }
    if (!(ob = present(str, this_player()))) {
	notify_fail("You are carrying no such thing.\n");
	return 0;
    }
    /* this is for the catching normal armour */
    /* extended syntax now works (e.g. "wear ring 2") */
    if (!function_exists("ev_wear", ob))
	return (status) ob->wear(ob->query_name());

    if (ob->query_worn()) {
	/* to accomodate for old wear syntax, I changed this to return 0 */
	notify_fail("You are already wearing it.\n");
	return 0;
    }
    if (ob->prevent_wear(this_player())) {
	write("You fail.\n");
	return 1;
    }
    /* wear(a) in player does say and write if succesful */
    if (worn = (object) this_player()->wear(ob)) {
	write("You already have an armour of class " + ob->query_type() + ".\n");
    if(worn)
    write( worn->short() ? "Worn armour "+worn->short()+"\n" : "");
	return 1;
    }
    ob->ev_wear(this_player());
    return 1;
}
