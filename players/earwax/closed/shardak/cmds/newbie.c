/*
 * written by verte to better support channels
 * using the now existant switch() in player.c [monitor.c]
 */

#include "../std.h"
#include "../def.h"
#include "../daemons.h"

inherit CMD;

status
main(string str)
{
    if (!str) return 0;
    if (str == "history" || str == "list") return 0;
    return (int)this_player()->broadcast((string)COLOURD->c_decode(str));
}