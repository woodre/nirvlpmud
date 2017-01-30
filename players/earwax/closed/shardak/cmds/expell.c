/*
 * EXPELL command (allies only) for senior servants and up
 * Balowski@Nirvana, Sept' 95
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../people.h"
inherit CMD;

status
main(string arg)
{
    object who, aob;

    if ((int) previous_object()->GuildClass() < C_SENIOR)
        return 0;
    if (!arg || !(who = find_player(arg)) || who->query_invis()) {
        notify_fail("Expell who?\n");
        return 0;
    }
    if (!(aob = present("allymark", who))) {
        write("You can only expell allies.\n");
        return 1;
    }
    CHANNELD->broadcast(capitalize(arg) + " is no longer an ally of the Servants.\n",
			0, "[Servants]");
    aob->remove_object(this_object());
    tell_object(who, "You have been expelled from the alliance with the Servants.\n");
    write_file(LOGDIR + "allies", ctime() + " : " +
                this_player()->query_real_name() + " expelled " + arg + ".\n");
    return 1;
}
