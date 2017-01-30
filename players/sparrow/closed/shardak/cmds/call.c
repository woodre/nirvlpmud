/*
 * Call the shop-keeper for the Shardak guild (c) Dragnar + Bal
 * The shop-keeper acts a lot like a portable shop
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../tasks.h"
#include "../macros.h"
#define COST 10

inherit CMD;

status
main(string who)
{
    object      demon;

    if (who != "merchant" && who != "demon") {
	notify_fail("Who do you want to call?\n");
	return 0;
    }
    needrank(3);
    needtask(TELEPORT_TASK);
    needmana(COST);

    if((status)this_player()->query_ghost()) return 0;

    /* this will cause shop to load, no way around it */
    demon = (object) SHOP->query_merchant();
    if (!demon) {
	write("There is no response.\n");
	return 1;
    }
    if (demon->summon(environment(this_player()))) {
	write("You raise your hands to your mouth and call upon the merchant.\n");
	say(this_player()->query_name() + " raises " +
	    this_player()->query_possessive() + " hands to " +
	    this_player()->query_possessive() +
	    " mouth and bellows out a command.\n");
	this_player()->add_spell_point(-COST);
    }
    return 1;
}
