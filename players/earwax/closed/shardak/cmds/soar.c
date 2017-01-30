/*
 * SOAR, another dragon command for Shardak's minion
 */
#pragma strict_types
#include "../std.h"
inherit CMD;

status
main(string str)
{
    object dragon;

    if (str)
        return 0;
    if (!(dragon = (object) previous_object()->Dragon()))
        return 0;
    if (!present(this_player(), dragon)) {
        write("The spirits in the dragon hiss: 'You must be mounted, master.'\n");
        return 1;
    }
    dragon->set_heal(35, -2);
}
