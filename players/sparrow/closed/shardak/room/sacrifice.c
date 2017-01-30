/*
 */
#include "/players/balowski/lib.h"
inherit WEAPON;
#include "../def.h"
string *names, *parents, *parent_too;

void reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("sacrificial dagger");
}

void init() {
    ::init();
    add_action("cmd_purge", "purge");
}

status cmd_purge(string str) {
    int i;
    string file;

    if(basename(this_player()) != (PATH + "priestess"))
        return 0;
    str = lower_case(str);
    file = "players/boltar/sprooms/daycare";

    if (!find_object(file) || !restore_object(file))
        return 0;
    i = member_array(str, names);
    if(i != -1) {
        file->set_name(i + " PURGED");
        file->set_parent(i + " PURGED");
        file->save_dc();
    }
    names = parents = parent_too = 0;
}
