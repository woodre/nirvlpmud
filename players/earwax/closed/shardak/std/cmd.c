/*
 * A base object for the command objects
 * Balowski@Nirvana, July '95
 */
#include "/players/balowski/lib.h"
#include "../macros.h"
inherit BASE;

/*
 * see if this_player can cast spell
 * returns 1 if he can
 */
int
cast(int rank, int trial, int cost)
{
    if (rank && this_player()->query_guild_rank() < rank) {
        write("Your guild rank is too low to master this spell.\n");
        return 0;
    }
    if (trial && !previous_object()->query_solved(trial)) {
        write("You have a trial to pass before you can master this spell.\n");
        return 0;
    }
    if (cost && qsp(this_player()) < cost) {
        write("You do not have enough spell points to sacrifice.\n");
        return 0;
    }
    if (!environment(this_player())
    ||  (int) environment(this_player())->query_property("no magic")) {
        write("The enchanted surroundings cause your spell to fail.\n");
        return 0;
    }
    return 1;
}

mixed
attack(string str)
{
    object ob;

    if (str) {
        ob = present(str, environment(this_player()));
        if (!ob) {
            write("There is no " + str + " here.\n");
            return 1;
        }
        if (!living(ob)) {
            write("Only a foolish warrior would try to kill something that is not alive.\n");
            return 1;
        }
    }
    else
        ob = (object) this_player()->query_attack();

    if (ob) 
        if (ob == this_player()) {
            write("You cannot attack yourself.\n");
            return 1;
        }
        else if (ob->is_player()) {
            write("Shardak does not allow you to use your powers against players.\n");
            return 1;
        }
    return ob;
}

/*
 * if refcount > 0 then this is an inherited object
 * and one shouldn't destruct it
 * return non-zero if clean_up should be called later
 */
void
clean_up(int refcount)
{
    if (!refcount)
        destruct(this_object());
}

/*
 * Disallow shadowing (unless priviledged in shadow master)
 */
status
query_prevent_shadow(object shadow)
{
    return 1;
}
