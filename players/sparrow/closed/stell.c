#include <ansi.h>

status
id(string str)
{
    return str == "stell";
}

string
short()
{
    object a, e;

    if((a = this_player()) && (e = environment()) &&
       (e == a))
      return "A sTeller [" + HIY + "invis" + NORM + "]";
}

void
init()
{
    add_action("cmd_stell", "sparrow");
    add_action("cmd_stell", "stell");
    add_action("cmd_spage", "spage");
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

    if(who != "sparrow" && who != "s")
      return 0;

    if(!(c = find_player("sparrow")))
    {
      write("Sparrow is not logged on.\n");
      return 1;
    }

    write("Establishing sLink over vLink(tm) connection...\n");
    if(!environment(c) || !interactive(c))
    {
      write("Sparrow is disconnected....closing connection.\n");
      return 1;
    }
    if((int)c->query_invis())
      write("Sparrow is invis....closing connection.\n");
    if(query_idle(c) > 120)
      write("Sparrow is idle....closing connection.\n");
    if(environment(c) &&
      (file_name(environment(c)) != "players/sparrow/workroom"))
      write("Sparrow may be busy.\n");

    write("<<" + HIY + "sTell" + NORM + ">> " + what + "\n");

    tell_object(c, HIW +
     (a = (string)this_player()->query_name()) +
      " tells you: " + NORM + what + "\n");
    c->add_tellhistory(CYAN + a + " told you: " + NORM + what);
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
cmd_stell(string arg)
{
    command("tell sparrow " + arg, this_player());
    return 1;
}

int cmd_spage()
{
  object ob;
  if(ob = find_player("sparrow"))
    tell_object(ob, BEEP+BEEP+BEEP+"\n\nBLING BLING!\n\n");
  write("Sorry, Sparrow is still toiling in RL.\n");
  return 1;
}
