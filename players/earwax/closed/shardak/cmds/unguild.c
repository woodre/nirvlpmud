/*
 * Unguild a member
 * Wizards only
 */
#pragma strict_types
#include <security.h>
#include "../def.h"
#include "../daemons.h"
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    object who, gob;
    string nom, msg;
    int gold, gxp, rnk, exp;
    
    if (this_player()->query_level() < 21) return 0;
    if (!arg) return (notify_fail("Usage: unguild <name>\n"), 0);
    if (!(who = find_player(arg))) {
	write(arg + " is not logged on.\n");
	return 1;
    }
    if ((int) who->query_level() >= APPRENTICE) {
	write("Wizard are immortals. Skipping final stage.\n");
	return 1;
    }

    nom = (string) who->query_name();
    if (!(gob = present(GUILD_ID, who))) {
	write(nom + " is not carrying the mark of Shardak.\n");
	return 1;
    }

    gxp = (int) who->query_guild_exp();
    rnk = (int) who->query_guild_rank();
    exp = (int) who->query_exp();

    if (!intp(gxp) || !intp(rnk) || !intp(exp)) {
	write(nom + "'s organism is broken.\n");
	return 1;
    }
    who->set_guild_name(0);		/* clear guild name */
    who->add_guild_exp(-gxp);		/* clear guild experience */
    who->add_guild_rank(-rnk);		/* clear guild rank */
    who->set_home(0);			/* clear alternative login room */
    gob->remove_object();
    destruct(gob);                      /* remove the mark of shardak */
					/* remove the guild file */
    rm("/" + SAVE_PATH + who->query_real_name() + ".o");

    gold = (int) who->query_money();
    who->add_money(-gold);
    HOARDD->add_hoard(gold);
    
    move_object(who, PATH + "throne");
    who->attacked_by(this_player());
    who->hit_player(10000);		/* lose one fourth exp */
    
    tell_object(who, "Your ghost drifts back to the church.\n");
    move_object(who, "room/church");
    log_file("GUILD", ctime() + ": " +
	     capitalize((string) who->query_real_name()) +
	     " expelled from Shardaks. By " +
	     capitalize((string) this_player()->query_real_name()) + "\n");

    msg = "Shardak digs his claws into " + nom + "'s throat and tears it asunder.\n";
    CHANNELD->broadcast(msg, 1, "{Servants}");
    msg = this_player()->query_name() +
      "'s mocking laughter seems to fill your head as he\n" +
      "releases the army of the Dark on " + nom + ". A raucous, deafening roar of\n" +
      "predatory anticipation echoes throughout the cavern.\n";
    CHANNELD->broadcast(msg, 1, "{Servants}");
    msg = nom + " has been expelled from the guild.\n";
    CHANNELD->broadcast(msg, 1, "{Servants}");
    
    return 1;    
}
