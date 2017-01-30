/*
 * Shardak guild, (tm) Dragnar/John
 * Shop storage room is (c) Balowski/Rasmus, 950323
 * log:
 * 950421 use ROOM
 * 951016 improved a little for better atmosphere
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"
#define MAX_LIST 30
inherit ROOM;

void
create()
{
    ::create();
    set_light(1);
    set_short("The merchant's bag");
    set_long("The merchant's bag.\n");
}

/*
 * present an object (value, short) to this_player()
 */
int
list(object ob)
{
    int value;
    
    value = 2*((int) ob->query_value());
    if (value)
	write(value + ":\t" + ob->short() + ".\n");
    return value;
}

/*
 * Give a list of buyable items in this store (player command)
 * Shows a maximum of MAX_LIST items using the list() function above
 *      string str:     "all"/0, "weapons", or "armours"
 *                      but anything goes.
 * Returns number of items shown
 */
int
cmd_list(string str)
{
    object ob;
    int max;

    if (str == "all")
	str = 0;

    max = MAX_LIST;
    for (ob = first_inventory(this_object());
	ob && max > 0;
	ob = next_inventory(ob))
    {
	if (!str ||
	    (str == "weapons" && function_exists("weapon_class", ob)) ||
	    (str == "armours" && function_exists("armour_class", ob)))
	{
	    if (list(ob)) max--;
	}
    }
    return (MAX_LIST - max);
}

/*
 * function for player command 'value'
 * this_player() will hear the cost of the specified item
 *      string what: id of item to value, 0 allowed
 */
status
cmd_value(string what)
{
    object      item;
    int         value;

    if (!what) {
	notify_fail("Value what?\n");
	return 0;
    }
    if (item = present(what, this_player())) {
	value = (int) item->query_value();
	write("Your " + what + " is worth " + value + " gold coins.\n");
	return 1;
    }
    if (!(item = present(what, this_object()))) {
	notify_fail("No such item in the store.\n");
	return 0;
    }
    if (value = 2*((int) item->query_value())) {
	write("The " + what + " would cost you " + value + " gold coins.\n");
	return 1;
    }
    return 0;
}

/*
 * function for player command 'buy'
 * this_player() will do the buying if possible
 *      string what: id of item to buy, 0 is allowed
 */
int
cmd_buy(string what)
{
    object      item;
    int         value;

    if (!(stringp(what) && (item = present(what, this_object()))))
	return 0;

    value = (int) item->query_value();
    if (!value || !intp( value))
	return -1;

    value *= 2;
    if ((int) this_player()->query_money() < value)
	return -2;

    if (!this_player()->add_weight((int) item->query_weight()))
	return -3;

    this_player()->add_money(-value);
    move_object(item, this_player());
    return value;
}

/*
 * store an item in this object
 * objects with a unique short are move to here, else dested
 *      object item:    object in the players inv.
 *                      player's encumbrance must be adjusted prior to call
 */
void
store(object item)
{
    string sh;
    object ob;

    sh = (string) item->short();
    ob = first_inventory(this_object());
    while (ob) {
	if ((string) ob->short() == sh) {
	    move_object(item, this_object());
	    destruct(item);     /* add_weight() is applied */
	    return;
	}
	ob = next_inventory(ob);
    }
    move_object(item, this_object());
}
