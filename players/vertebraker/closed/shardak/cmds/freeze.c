/*
 * FREEZE command for the law enforcers in the guild
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
    if (!arg || !(who = find_player(arg)) || who == this_player()) {
        notify_fail("Freeze who?\n");
        return 0;
    }
    if (!(gob = present(OBJID, who))) {
        write(capitalize(arg) + " does not bear the mark of Shardak.\n");
        return 1;
    }
    if (((int) gob->GuildClass() > C_LAW) || (int)who->query_level() > 21) {
	write("You fail.\n");
	return 1;
    }
    if (gob->Freeze()) {
        write(capitalize(arg) + " is already frozen.\n");
        return 1;
    }
    gob->Freeze(1);
    gob->save_me();             /* save stats, cuz init restores */
    move_object(gob, who);      /* force an init() */
    CHANNELD->broadcast("The law has deprived " + capitalize(arg) +
                        " of " + who->query_possessive() + " powers.\n",
			0, "{Servants}");
    write_file(LOGDIR + "freeze", ctime() + " : " +
                this_player()->query_real_name() + " froze " + arg + "\n");
    return 1;
}
