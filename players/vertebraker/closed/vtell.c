#include <ansi.h>

status
id(string str)
{
    return str == "vtell";
}

string
short()
{
    object a, e;

    if((a = this_player()) && (e = environment()) &&
       (e == a))
      return "A vTell [" + HIW + "invis" + NORM + "]";
}

void
init()
{
    add_action("cmd_vtell", "vert");
    add_action("cmd_vtell", "vtell");
    add_action("cmd_vpage", "vpage");
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

    if(who != "vertebraker" && who != "v" && who != "verte")
      return 0;

    if(!(c = find_player("vertebraker")))
    {
      write("Verte is not logged on.\n");
      return 1;
    }

    write("Establishing vLink...\n");
    if(!environment(c) || !interactive(c))
    {
      write("He is disconnected.\n");
      return 1;
    }
    if((int)c->query_invis())
      write("He is invis.\n");
    if(query_idle(c) > 120)
      write("He is idle.\n");
    if(environment(c) && 
      (file_name(environment(c)) != "players/vertebraker/workroom"))
      write("He may be busy.\n");

    write("[" + HIW + "vtell" + NORM + "] " + what + "\n");

    tell_object(c, HIW + 
     (a = (string)this_player()->query_name()) +
      " tells you: " + NORM + what + "\n");
    c->add_tellhistory(HIW + a + " told you: " + NORM + what);
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
cmd_vtell(string arg)
{
    command("tell vertebraker " + arg, this_player());
    return 1;
}

int cmd_vpage()
{
  object ob;
  if(ob = find_player("vertebraker"))
    tell_object(ob, BEEP+BEEP+BEEP+"\n\nBLING BLING!\n\n");
  write("No can do, V split the chicken coop homes.\n");
  return 1;
}
