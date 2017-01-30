/* god bless america */

object *z;
string *a;

id(str) { return str == "ghost" || 
          str == "ghost of patton" || str == "ghost of gen. patton" || str == "patton"; }

reset(x) { if(!x) { z=a=({}); } }

query_name() { return "ghost of Gen. Patton"; }

short() { return query_name(); }

init()
{
  object x;
  if(root()) return;
  if((x = this_player()) && (member_array(x, z) == -1))
  {
    string kds;
    kds = query_ip_name(x);
    if(!kds) return;
    if(sscanf(kds, "%s.com") || sscanf(kds, "%s.us") || sscanf(kds, "%s.net") ||
       sscanf(kds, "%s.org"))
      call_out("bing", 2, x);
    z += ({ x });
  }
  add_action("schteal", "steal");
}

bing(x)
{
  if(objectp(x))
    tell_object(x, "\n" + short() + " looks you over and says:\n\n\
  Oh, A fellow yankee eh?\n\
  Hmph.  Damned terrorist bastids.  Makes me wish I was still in the army.\n\
  We'd obliterate the sonsofbitches.\n\n");
}

long()
{
    write("\
The incorporeal form of the greatest United States general, the hero George Patton,\n\
brought back to life in light of the recent events which shook the nation.\n\
He is floating next to a cardboard box full of small American flags, from which\n\
you may 'steal' a flag.\n");
}

schteal(arg)
{
  if(arg == "flag" || arg == "a flag")
  {
    string n;
    n = (string)this_player()->query_real_name();
    if(member_array(n, a) > -1)
      return (write("The ghost slaps your hand in a ghostlike manner.\n"), 1);
    write("You take an American flag.\nThe ghost smiles faintly at you.\n");
    this_player()->remote_say((string)this_player()->query_name() + " takes a flag.\n\
The ghost smiles faintly at " + (string)this_player()->query_name() + ".\n");
    a += ({ n });
    move_object(clone_object("/players/vertebraker/misc/amer_flag"), this_player());
    return 1;
  }
  return (notify_fail("You may steal a flag.\n"), 0);
}
