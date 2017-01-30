/*
 * MOUNT command for the Shardak Assassins
 * Dragnar and Balowski, Nirvana '95
 */
#pragma strict_types
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    object dragon, owner;

    if (!arg || !(dragon = present(arg, environment(this_player())))) {
        notify_fail("Mount what?\n");
        return 0;
    }
    if (!living(dragon)) {
        notify_fail("You can not mount the " + arg + ".\n");
        return 0;
    }
    if (this_player()->query_attack()) {
        notify_fail("You are too occupied with fighting to mount anything.\n");
        return 0;
    }
    if (!dragon->mountable(this_player())) {
        notify_fail("The " + dragon->query_name() + " refuses to let you mount " +
                ((string) dragon->query_objective() || "it") + ".\n");
        return 0;
    }
    dragon->MountedBy(this_player());
    move_object(this_player(), dragon);
    return 1;
}
