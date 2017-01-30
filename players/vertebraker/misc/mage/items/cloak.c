inherit "/players/vertebraker/closed/std/treasure";

int worn;

void
reset(int arg)
{
    if(arg) return;
    set_id("dark brown cloak");
    add_id("brown cloak");
    add_id("cloak");
    set_short("A dark brown cloak");
    set_long("\
A thick, dark brown cloak worn for traveling.  It\n\
can be worn in addition to any armor.  The fabric is quite\n\
soft and smooth.\n");
    set_value(400 + random(100));
}

status
drop()
{
    object z;

    if((z = this_player()) && worn)
      command("remove dark brown cloak", z);
}

void
init()
{
    ::init();
    add_action("cmd_wear", "wear");
    add_action("cmd_remove", "remove");
}

status
cloak_check(object heh)
{
    object ung;

    ung = first_inventory(heh);
    while(ung)
    {
      if((status)ung->id("dark brown cloak") && (status)ung->query_worn())
        return 1;
      ung = next_inventory(ung);
    }

    return 0;
}
     

status
cmd_wear(string str)
{
    object z;

    if(id(str) && (environment() == (z = this_player())))
    {
      if(worn)
      {
        notify_fail("You are already wearing it!\n");
        return 0;
      }
      if(cloak_check(z))
      {
        notify_fail("You are already wearing a cloak.\n");
        return 0;
      }
      write("You put the brown cloak around your shoulders.\n");
      say((string)z->query_name() + " wears a dark brown cloak.\n");
      worn = 1;
      return 1;
    }

    return 0;
}

status
cmd_remove(string str)
{
    object z;
    if(id(str) && (environment() == (z = this_player())))
    {
      if(!worn)
      {
        notify_fail("You aren't wearing it.\n");
        return 0;
      }
      write("You remove the brown cloak.\n");
      say((string)z->query_name() + " removes a dark brown cloak.\n");
      worn = 0;
      return 1;
    }
    
    return 0;
}

string
short()
{
    return ::short() + (worn ? " (worn)" : "");
}

status
query_worn()
{
    return worn;
}

status
is_armor()
{
    string vrb;
    if((vrb = query_verb()) && (vrb == "ready" || vrb == "#"))
      return 1;
    else return 0;
}
