#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

status 
main(string str) {
    string Dork, Stuff;
    object DorkObj, CBear;

    if(!str || sscanf(str, "%s %s", Dork, Stuff) < 2)
      return(notify_fail( "\
Syntax: \"at [who] [cmd]\".\n"), 0);
    DorkObj = find_player(Dork);
    if(!DorkObj || !environment(DorkObj))
      return(notify_fail( "\
Cannot find player " + capitalize(Dork) + ".\n"), 0);
    CBear = environment(this_player());
    move_object(this_player(), environment(DorkObj));
    command(Stuff, this_player());
    move_object(this_player(), CBear);
    write ("Ok.\n");
    return 1;
}

get_help() {
    string help;
    help = "Do a command at a players location";
    return help;
}