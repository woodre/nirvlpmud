/* Wholesale theft from Vertebraker@Nirvana */

#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>
#define TOOL "/players/vital/closed/tool/p.c"

string short_desc;

status
id(string str) {
    return str == "phone" || str == "vitaltell" || str == "vman";
}

string
short()
{
    object a, e;

    if((a = this_player()) && (e = environment()) && (e == a)) {
        short_desc = TPN+"'s Cellular Phone [" + HIW + "invis" + NORM + "]";
        return short_desc;
    }
}

int
long()
{
    string com1, com2, com3;
    object a, e;

    if((a = this_player()) && (e = environment()) && (e == a))
    {
        com1 = "Type 'vital <msg>' to get in touch with him.\n";
        com2 = "Type 'jumpstart' to reset the phone if things aren't working.\n";
        com3 = "Type 'giving <playername>' to give a phone to someone else.\n";
        write( short_desc + "\n" + com1 + com2 + com3);
    }
    return 1;
}

void
init()
{
    add_action("cmd_vtell", "vital");
    add_action("cmd_vtell", "vtell");
    add_action("cmd_tell", "tell");
    add_action("refreshed", "jumpstart");
    add_action("the_giving", "giving");
}

the_giving(string str)
{
    object bob, p;
    if (!str)
    {
        notify_fail("You have to give a player's name.\n");
        return 0;
    }
    bob = find_player(str);
    if (!bob)
    {
        notify_fail("Unable to find anyone named " + capitalize(str) +
            " in the game.\n");
        return 0;
    }
    else if (bob)
    {
        write("The Giving has succeeded. " + capitalize(str) +
            " now has a cellular phone.\n");
        write("Tell them how to use it.\n");
        tell_object(bob, capitalize(this_player()->query_real_name()) +
            " has given you a cellular phone to contact the coder Vital.\n");
        p = clone_object("/players/vital/closed/tool/p.c");
        move_object(p,bob);
        return 1;
    }
    notify_fail("Hmm...\n");
    return 0;
}

status
cmd_tell(string arg)
{
    string who, what, a;
    object c;

    if (!stringp(arg) || sscanf(arg, "%s %s", who, what) < 2) {
      write("Tell what?\n");
      return 1;
    }

    if (who != "vital")
      return 0;

    if (c = find_player("vital"))
    {
        write("Establishing Private Connection...\n");
        if(!environment(c) || !interactive(c))
        {
            write("He is disconnected.\n");
            return 1;
        }
        if((int)c->query_invis()) write("He is invis.\n");
        if(query_idle(c) > 120) write("He is idle.\n");
        if(environment(c) && (file_name(environment(c)) != "players/vital/workroom")) write("He may be busy.\n");
        tell_object(c, HIW + (a = (string)this_player()->query_name()) + " tells you: " + NORM + what + "\n");
            c->add_tellhistory(HIW + a + " told you: " + NORM + what);
    }
    else
    {
        write_file("/players/vital/closed/tool/p",random_color()+TP->query_real_name()+NORM+" :: "+what+" <--> "+ctime(time())+".\n");
        write(BLU+"Writing to Offline Log"+NORM+"\n");
    }
    write("[" + RED + "OK" + NORM + "] " + what + "\n");

    
    return 1;
}

status
get() {
    return 1;
}
status
drop() {
    return 1;
}

status
cmd_vtell(string arg) {
    command("tell vital " + arg, this_player());
    return 1;
}

query_auto_load(){ return TOOL+":"; }

refreshed()
{
    object then, now, here;
    then = this_object();
    here = environment(then);
    now = clone_object(TOOL);
    move_object(now, here);
    destruct(then);
    write("[" + RED + "OK" + NORM + "]\n");
    return 1;
}