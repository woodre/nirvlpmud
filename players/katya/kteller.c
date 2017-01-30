#include "/players/vertebraker/ansi.h"

status
id(string str)
{
    return str == "ktell";
}

string
short()
{
    object a, e;

    if((a = this_player()) && (e = environment()) &&
       (e == a))
      return "A ktell [" + HIM + "invis" + NORM + "]";
}

void
init()
{
    add_action("cmd_ktell", "katya");
    add_action("cmd_ktell", "ktell");
    add_action("cmd_tell", "tell");
}

status
cmd_tell(string arg)
{
    string who, what, a;
    object c;

    if(!stringp(arg) || sscanf(arg, "%s %s", who, what) < 2)
    {
      write("Tell what?\n");
      return 1;
    }

    if(who != "katya" && who != "k" && who != "katya")
      return 0;

    if(!(c = find_player("katya")))
    {
      write("Katya is not logged on.\n");
      return 1;
    }
    write("You send...\n");
    if(!environment(c) || !interactive(c))
    {
      write("He is disconnected.\n");
      return 1;
    }
    if((int)c->query_invis())
      write("She is invis.\n");
    if(query_idle(c) > 120)
      write("She is idle.\n");
    if(environment(c) && 
      (file_name(environment(c)) != "players/katya/workroom"))
      write("She might be busy.\n");

    write("[" + HIM + "ktell" + NORM + "] " + what + "\n");

    tell_object(c, HIM + 
     (a = (string)this_player()->query_name()) +
      " tells you: " + NORM + what + "\n");
    c->add_tellhistory(HIM + a + " told you: " + NORM + what);
    c->Replyer((string)this_player()->query_real_name());
    
    return 1;
}

status
get()
{
    return 1;
}
status
drop()
{
    return 1;
}

status
cmd_ktell(string arg)
{
    command("tell katya " + arg, this_player());
    return 1;
}
