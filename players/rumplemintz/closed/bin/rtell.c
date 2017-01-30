#include <ansi.h>

int
rtell(string str)
{
    string what;
    object who;

    if (!str || sscanf(str,"%s %s", who, what) !=2)
    {
        notify_fail("Usage: rtell <who> <what>\n");
        return 0;
    }
    who = find_player(who);
    if (!who)
    {
        notify_fail("Cannot find " + capitalize(str) +".\n");
        return 0;
    }
    tell_object(who,
        BOLD+BLK+ ".o0O"+BLU+this_player()->query_name()+BLK+"O0o."+NORM+
        ": " + what + "\n");
    write("You tell " + who->query_real_name() + ": " + what + "\n");
    who->add_tellhistory(this_player()->query_name()+" told you: "+what+"");
    who->Replyer("rumplemintz");
    return 1;
}
