/*
 * UNFREEZE command for the law enforcers in the guild
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
    object who, gob;

    if ((int) previous_object()->GuildClass() < C_LAW)
        return 0;
    if (!arg || !(who = find_player(arg))) {
        notify_fail("Unfreeze who?\n");
        return 0;
    }
    if (!(gob = present(OBJID, who))) {
        write(capitalize(arg) + " does not bear the mark of Shardak.\n");
        return 1;
    }
    if (!gob->Freeze()) {
        write(capitalize(arg) + " is not frozen.\n");
        return 1;
    }
    gob->Freeze(1);
    gob->save_me();             /* save because init restores */
    move_object(gob, who);      /* force an init() */
    CHANNELD->broadcast("The law has granted " + capitalize(arg) + " " +
                        who->query_possessive() + " powers back.\n",
			0, "{Servants}");
    write_file(LOGDIR + "freeze", ctime() + " : " +
                this_player()->query_real_name() + " unfroze " + arg + "\n");
    return 1;
}
