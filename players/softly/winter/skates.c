inherit "/obj/treasure";

static int worn;

void reset(int arg)
{
    set_id("ice skates");
    set_alias("skates");
    set_short("Ice skates");
    set_long( "\
A pair of well-made ice skates.\n\
You may 'wear', 'remove' or 'return' them.\n");
    set_weight(1);
    set_value(50);
}

status drop()
{
    if(worn && environment()) 
      command("remove skates", environment());
    else if(worn) worn = 0;
}

void init()
{
    ::init();
    add_action("cmdKick","kick");
    add_action("cmdWear","wear");
    add_action("cmdReturn","return");
    add_action("cmdRemove","remove");
}
string short()
{
   if(!living(environment()))
   {
     worn = 0;
     return short_desc;
   }
   return short_desc + (worn ? " (worn)" : "");
}

status skates_check()
{
    int x, z;
    object *inv;
    inv = all_inventory(this_player());
    for(x = 0; x < sizeof(inv); x ++)
    {
      if(inv[x]->id("ice skates") && inv[x]->query_worn())
        z = 1;
    }
    return z;
}

status cmdWear(string str)
{
    string *armors;
    if(!id(str) || environment() != this_player())
      return 0;
    if(worn)
    {
      notify_fail("You are already wearing your skates.\n");
      return 0;
    }
    armors = (mixed)this_player()->query_armor();
    if(armors && member_array("boots", armors) != -1)
    {
      notify_fail("\
You cannot wear boots and skates at the same time.\n");
      return 0;
    }
    if(skates_check())
    {
      notify_fail("You are already wearing a pair of skates.\n");
      return 0;
    }
    write("You put on your ice skates.\n");
    say((string)this_player()->query_name() + "\
 puts on " + possessive(this_player()) + " ice skates.\n");
    worn = 1;
    return 1;
}

status cmdRemove(string str)
{
    if(!id(str) || environment() != this_player())
      return 0;
    if(!worn)
    {
      notify_fail("You aren't wearing those skates.\n");
      return 0;
    }
    write("You remove your ice skates.\n");
    say((string)this_player()->query_name() + "\
 removes " + possessive(this_player()) + " ice skates.\n");
    worn = 0;
    return 1;
}

status id(string str)
{
    if(worn && previous_object() &&
      (string)previous_object()->query_type() == "boots")
      return str == name || str == alias_name || str == "notarmor";
    else
      return str == name || str == alias_name;
}

status query_worn() { return worn; }

is_softly() { return 1; }

status cmdKick(string str)
{
    if(!worn) return 0;
    write("You try to kick, but land sprawling on your bum!\n");
    say((string)this_player()->query_name() + " kicks in the air, and falls on " + possessive(this_player()) + " bum!\n");
    return 1;
}

status cmdReturn (string str)
{  
    if(!id(str) || environment() != this_player()) return 0;
    if(worn)
    {
      notify_fail("\
You cannot return the ice skates if you are wearing them!\n");
    return 0;
    }
    say((string)this_player()->query_name() + "\
 returns the ice skates.\n ");
    write("\
You feel pleased as you return the ice skates for Mr. Bryant.\n");
    this_player()->add_weight(-1);
    destruct(this_object());
    return 1;
}
