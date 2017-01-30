/*
 * Shardak guild, (tm) Dragnar/John & Balowski/Rasmus
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../people.h"
inherit CMD;

status
main(string who)
{
    object ob;

    if (!interactive(this_player()) ||
	(int) previous_object()->GuildClass() < C_SENIOR)
	return 0;

    if (!who || !(ob = find_player(who)) || ob->query_invis()) {
	notify_fail("Who do want to invite into the guild?\n");
	return 0;
    }

    /* insert ob in the invited-list in the cave */
    call_other(PATH + "cave", "invited", ob);

    tell_object(ob, "\
You have been invited to join the ranks of Shardak, the dragon-man.\n\
The ghost in the wastelands can provide you with more information.\n");
    CHANNELD->broadcast(capitalize(who) + " has been invited by " +
			this_player()->query_name() + " to join our ranks.\n",
			0, "{Servants}");
    write_file(LOGDIR + "invite", ctime() + " : " +
				  this_player()->query_real_name() +
				  " invited " + who + "\n");
    return 1;
}
