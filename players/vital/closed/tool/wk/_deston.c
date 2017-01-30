/* dests an object off a player */
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
    string who, id, notell; object freak, thing;
    if(!str || sscanf(str,"%s %s",who,id) != 2) {
        notify_fail("Syntax: 'deston <who> <what> [notell]'\n");
        return 0;
    }
    freak = find_player(who);
    if(sscanf(id,"%s %s",id,notell) != 2) {
        if(!freak) {
            notify_fail("Freak not logged on.\n");
            return 0;
        }
        thing = present(id,freak);
        if(!thing) {
            notify_fail("Object does not exist.\n");
            return 0; }
        destruct(thing);
        freak->recalc_carry();
        write("You destruct a "+id+" from "+freak->TPN+"'s inventory.\n");
        tell_object(freak, BOLD + "\t\t....something disappears from your inventory....\n" + NORM);
        return 1;
    }
    if(!freak) {
        notify_fail("Freak not logged on.\n");
        return 0;
    }
    thing = present(id,freak);
    if(!thing) {
        notify_fail("Object does not exist.\n");
        return 0;
    }
    destruct(thing);
    freak->recalc_carry();
    write("You destruct a "+id+" from "+freak->TPN+"'s inventory.\n");
    return 1;
}

get_help()
{
  string help;
  help = "Dests Objects off Players - Syntax: deston <player> <object>";
  return help;
}