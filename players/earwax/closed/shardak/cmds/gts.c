/*
 * GTS command for the Shardak guild
 * muffle guild channel
 * by Drag and Bal
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
inherit CMD;

status
main(string arg)
{
    if (arg) return 0;
    if (previous_object()->Muffled(1)) {/* toggle it */
	CHANNELD->deregister(this_player(), ({"[Servants]","{Servants}",}));
	write("You are no longer listening to the Servants' channel.\n");
    }
    else {
	/* a bit patchy.. prevent allies from getting on the guild chan */
	if ((int) previous_object()->GuildClass() < 0) {
	    CHANNELD->register(this_player(), "[Servants]");
	}
	else {
	    CHANNELD->register(this_player(), ({"[Servants]","{Servants}",}));
	}
	write("You are now listening to the Servants' channel.\n");
    }
    return 1;
}
