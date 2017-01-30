/*
 * FLY command for the Shardak Assassins
 * by Dragnar and Balowski for Nirvana, sometime in '95
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../macros.h"
#define MAX_FLY 5
#define MAX_RUN 4
#define GUILD_COST 55
inherit CMD;

static mapping  valid_dirs;     /* mapping of valid fly's */

void
reset(int arg)
{
    if (!arg)
        valid_dirs = ([
                "e":"east","w":"west","n":"north","s":"south",
                "nw":"northwest","ne":"northeast",
                "exit":"exit","leave":"leave","pass":"pass",
                "sw":"southwest","se":"southeast",
                "east":"east","west":"west","north":"north","south":"south",
                "northwest":"northwest","northeast":"northeast",
                "southwest":"southwest","southeast":"southeast",
                "u":"up","up":"up","d":"down","down":"down",
                "in":"in","out":"out","back":"back",
                "step rift":"step rift","enter portal":"enter portal",
        ]);
}

mapping query_valid_dirs() { return valid_dirs; }

void
go_fly(object dragon, string cmd_list)
{
    string          cmd, eff;
    int             count, rep;
/* reported bug says fly command by-passes the mount block on 
   using dragon while in combat. Copied this out of mount.c, should
   fix the issue if it exists or do nothing at all. -Bp dec 2002 */

    if (this_player()->query_attack()) {
        notify_fail("You are too occupied with fighting to mount anything.\n");
        return 0;
    }

    count = MAX_FLY;
    while (cmd_list && count > 0) {
        if (!sscanf(cmd_list, "%s,%s", cmd, cmd_list)) {
            cmd = cmd_list;
            cmd_list = 0;
        }
        if (cmd == "guild") {
            if (environment(dragon)->realm()) {
                write("The spirits within the dragon hiss: 'You may not do that here.'\n");
                break;
            }
            if (qsp(this_player()) < GUILD_COST) {
                write("You need more mana before you can fly to the guild.\n");
                break;
            }
	    write("Your dragon flies to the guild.\n");
            say(capname + "'s dragon takes off into the sky.\n");
            move_object(dragon, (PATH + "cave"));
            say("A dragon swoops down from the sky.\n");
            this_player()->add_spell_point(-GUILD_COST);
	    count--;
            continue;
        }

	rep = 1;
	sscanf(cmd, "%d%s", rep, cmd);
        if (cmd == "") continue;
	if (rep < 1 || rep > MAX_FLY) continue;
        if (!(eff = valid_dirs[cmd])) {
            write("The spirits in the dragon hiss: 'We are not allowed to " +
		  cmd + ", master.'\n");
            break;
        }
	while (rep--) {
	    if (!command(eff, dragon)) {
		write("The spirits in the dragon hiss: 'We can not go " + eff +
		      " master.'\n");
		count = 0;
		break;
	    }
	    else {
		write("Your dragon flies " + eff + ".\n");
		count--;
	    }
	}
    }
}

status
run(string str)
{
    string *dirs, eff;
    int i, size;
    object prev;

    if (!str) {
        notify_fail("Run where?\n");
        return 0;
    }

    size = sizeof(dirs = explode(str, ","));
    while (i < size && i < MAX_RUN) {
        if (!(eff = valid_dirs[dirs[i]])) {
            write("You cannot run <" + dirs[i] + ">. You stop.\n");
            break;
        }
        prev = environment(this_player());
        command(eff, this_player());
        if (prev == environment(this_player())) break;
        i++;
    }
    if (size > MAX_RUN)
        write("You stop to catch your breath.\n");
    return 1;
}

status
main(string str)
{
    object env, dragon;
    int mounted;

    if (!(dragon = (object) previous_object()->Dragon())) {
        notify_fail("Do you have wings?\n");
        return 0;
    }
    mounted = objectp(present(this_player(), dragon));
    if (!mounted && !present(dragon, environment(this_player()))) {
        notify_fail("Do you have wings?\n");
        return 0;
    }
    if (!str) {
        notify_fail(
"The spirits in the dragon hiss: 'Where do you wish to fly, master?'\n");
        return 0;
    }
    if (dragon->CheckBusy()) return 1;

    if (!mounted) {
        if (this_player()->query_attack()) {
            write("You cannot while you are engaged in combat.\n");
            return 1;
        }
        write("Hurriedly you mount your dragon.\n");
        say("With great speed " + this_player()->query_name() +
            " climbs onto the back of " + this_player()->query_possessive() +
            " dragon.\n");
        move_object(this_player(), dragon);
    }
    env = environment(dragon);
    go_fly(dragon, str);

    if (env != environment(dragon)) {
        dragon->long();
        write("\
The spirits in the dragon hiss: 'We have flown as you commanded, master.'\n");
    }
    return 1;
}
