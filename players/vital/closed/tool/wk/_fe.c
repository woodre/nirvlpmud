#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str) {
    string who, what;
    object ob;
    if(!str || sscanf(str, "%s %s", who, what) < 2) return 0;
    ob = find_player(who);
    if(!ob) return 0;
    write("<afar> You " + what + "\n");
    tell_object(ob, "<afar> " + TPN + " " + what + "\n");
    return 1;
}

get_help() {
    string help;
    help = "My faremote";
    return help;
}