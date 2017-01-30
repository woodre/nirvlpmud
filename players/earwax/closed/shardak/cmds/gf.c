/*
 * GE command for the Shardak guild
 * free guild emote
 * by Dragnar and Balowski
 */
#pragma strict_types
#include "../include/std.h"
#include "../include/def.h"
#include "../include/ansi.h"
inherit CMD;

status
main(string str)
{
    if (!str) {
	notify_fail("Feel what?\n");
	return 0;
    }
    if (previous_object()->Muffled()) {
	notify_fail("You are not listening to the Servants' channel.\n");
	return 0;
    }
    return (int) CHANNELD->feeling(str, "[Servants]", RED + "[Servants]" + NORM);
}
