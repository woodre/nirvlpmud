/*
 * GSAVE command for the Shardak guild
 * save guild statistics
 */
#pragma strict_types
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    string          file;

    write("Saving guild statistics.\n");
    previous_object()->save_me();
    return 1;
}
