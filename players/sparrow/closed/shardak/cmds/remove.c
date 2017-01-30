/*
 * REMOVE command for the Servants of Shardak (for special armour)
 * In case of difficulty: use drop
 * (c) Balowski/Rasmus H. Hansen 1996
 */
#pragma strict_types
#include "../std.h"
inherit CMD;

void
RemoveAll()
{
    object ob, next;
    int hit;

    next = first_inventory(this_player());
    while (ob = next) {
	next = next_inventory(ob);
	if (!ob->query_worn()) continue;
	hit++;
	if (!function_exists("ev_remove", ob)) {
	    write(ob->query_name() + ": ");
	    ob->remove(ob->query_name());
	    continue;
	}
	if (ob->prevent_remove()) write(ob->query_name() + ": You fail.\n");
	else {
	    write(ob->query_name() + ": ");
	    /*this_player()->stop_wearing(ob->query_name());*/
	    ob->ev_remove();
	}
    }
    if (!hit) write("You are not wearing anything.\n");
}

status
main(string str)
{
    object ob, worn;

    if (!str) {
	notify_fail("Remove what?\n");
	return 0;
    }
    if (str == "all") {
	RemoveAll();
	return 1;
    }
    if (!(ob = present(str, this_player()))) {
	notify_fail("You are carrying no such thing.\n");
	return 0;
    }
    /* this catches the normal armour, allows extended syntax */
    if (!function_exists("ev_remove", ob))
	return (int) ob->remove(ob->query_name());

    if (!ob->query_worn()) {
	/* to accomodate for old wear syntax, I changed this to return 0 */
	notify_fail("You are not wearing it.\n");
	return 0;
    }
    if (ob->prevent_remove()) {
	write("You fail.\n");
	return 1;
    }
    /* stop_wearing(name) in player does say and write if successful */
    /*this_player()->stop_wearing(ob->query_name());*/
    ob->ev_remove();
    return 1;
}

