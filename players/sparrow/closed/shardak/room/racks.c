/* 
 * Shardak guild - (tm) Dragnar/John
 * racks.c is (c) Balowski/Rasmus, April 17th 1995.
 * Last change:
 * Storage room for the smith's workings
 */
#include "/players/balowski/lib.h"
#include "/players/dragnar/closed/color.h"
#include "../def.h"
#define MAX_LIST 30
#define PERIOD 60 /* every 30 minutes */
static int      LastForge;      /* last time weapons were forged */

status
id(string str)
{
    return str == "racks";
}

string
short()
{
    return "Weapon racks";
}

void
long()
{
    write("Weapon racks\n");
}

void
reset(int arg)
{
    object ob;

    /* make the standard assortment */
    if (!arg) {
        ob = clone_object("/obj/armor");
	ob->set_name("buckler");
	ob->set_short("buckler");
	ob->set_type("shield");
	ob->set_weight(1);
	ob->set_ac(1);
	ob->set_value(75);
	move_object(ob, this_object());
	
	ob = clone_object(OBJDIR + "bardiche");
	move_object(ob, this_object());

	LastForge = time();
    }
}

status
can_put_and_get(string str)
{
    /* only necessary if I move this to the smithy */
    if (str)    /* There's no looking at my inv */
	return 0;
    return 1;   
}

/*
 * once every PERIOD seconds the smith can make weapons
 */
void
manufacture()
{
    int         i,
		forge;          /* the max number of weapons to change */
    int         class;
    object      *inv;
    object      ob;

    forge = (time() - LastForge)/PERIOD;
    if (!forge) return;
    LastForge += forge*PERIOD;  /* increase time accordingly */

    /* checking the last ones first */
    i = sizeof(inv = all_inventory());
    while (i--) {
	if (forge <= 0) break;          /* quit checking */

	if ((string) inv[i]->query_info() == "shardak")
	    continue;

	if (function_exists("weapon_class", inv[i])) {
	    if (inv[i]->id("holy avenger")) {
		ob = clone_object(OBJDIR + "dblade");
	    }
	}
	else if (function_exists("armor_class", inv[i])) {
	    switch ((string) inv[i]->query_type()) {
	      case "ring":
		ob = clone_object(OBJDIR + "murder");
		break;
	      case "shield":
		break;
	    }
	}

	if (ob) {
	    ob->set_info("shardak");
	    move_object(ob, this_object());
	    destruct(inv[i]);
	    ob = 0;
	    forge--;
	}
    }
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

    manufacture();
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

void
work_on_item(string path)
{
     call_out("finished", PERIOD, path);
}

void
finished(string path)
{
     object ob;
     ob = clone_object(path);
     move_object(ob, this_object());
     ob->set_info("shardak");
}
