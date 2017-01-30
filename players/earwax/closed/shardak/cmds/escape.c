/*
 * ESCAPE spell for the Shardak guild
 * Unprecise teleport to guild
 * by Drag and Bal, '95
 * cost, timbuktu, msgs rewritten by verte
 */
#pragma strict_types
#include "../def.h"
#include "../std.h"
#include "../tasks.h"
#include "../macros.h"
inherit CMD;

#define COST 65

status
main(string arg)
{
    mixed *exits;
    string *err_exits;
    string home;
    int r;
    int c;
    if (arg)
        return 0;
    c = COST + random(5);
    needrank(3);
    needmana(COST);
    needtask(TELEPORT_TASK);
    if(this_player()->query_ghost()) return 0;

    this_player()->add_spell_point(-COST);
    if (environment(this_player()) && environment(this_player())->realm()) {
        write("Your surroundings have been enchanted and your escape is blocked.\n");
        say(this_player()->query_name() +
            " mutters a magic formula of escape, but nothing happens.\n");
        return 1;
    }
    write("You speak the magic words of escape.\n");
    say(this_player()->query_name() + " mutters a magic formula of escape.\n");
    home = PATH + "grotto";
    if (random(125) >= 25) {
        /* send caster to a room not being the target room */
        exits = m_values((mapping) call_other(home, "query_exits"));
        r = random(1 + sizeof(exits));

        if (r < sizeof(exits))
            /* send caster to one of the adjancent rooms */
            home = exits[r];
        else {
            /* send caster to timbuktu - rewritten by verte */
        err_exits = explode(read_file("/open/TELE_ERR"),"\n");
        home = err_exits[random(sizeof(err_exits))];
        
        }
    }

    if (!stringp(home) || !find_object(home)) {
        /* there might be ints and objects in the exits array */
        home = PATH + "deepdown";
    }

    /* if no env and home not yet loaded I get an unintended effect.. */
    if (find_object(home) == environment(this_player())) {
        write("There was no effect.\n");
        say("It did not look very successful.\n");
    }
    else
        this_player()->move_player("in a puff of smoke#" + home);
    return 1;
}
