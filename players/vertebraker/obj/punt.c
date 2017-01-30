#include "../define.h"

reset(x) { if(!x && !root()) call_out("hahaha", 5); }
status get() { return 1; }

status drop() { return 1; }

status id(string str) { return str == "punter"; }

init()
{
    add_action("cmdPunt","punt");
}

void worship_me(object ob)
{
    int x;
    object *inv;
    
    inv = all_inventory(environment(ob));

    for( x = 0; x < sizeof(inv); x ++ )
      if(inv[x] != ob && inv[x]->is_player())
        command("worship " + (string)ob->RN, inv[x]);
}

status cmdPunt(string str)
{
    int yds, z;
    object foo;
    string msg;

    if(!str) return 0;
    foo = find_living(str);
    if(!foo || !present(foo, environment(this_player())))
    {
      notify_fail("\
You don't see that foo anywhere!\n");
      return 0;
    }
    yds = 1000 + random(18000);
    if(yds == 2001)
      msg = HIM + "A mothafuckin' space odyssey!" + NORM;
    else if(yds < 2002)
      msg = "I kinda feel sorry for you.  Hmm. No.";
    else if(yds < 4000)
      msg = "Seeya!  Wouldn't wanna be ya!";
    else if(yds < 7000)
      msg = "Is that a bird?  A plane?   No, it's your ass!";
    else if(yds < 10000)
      msg = "Aww.  You done got fucked up! " + HIC + ":~(" + NORM;
    else if(yds < 13000)
      msg = "That was from God foo!";
    else if(yds < 15000)
      msg = RED + "Splat.\n" + NORM +
     "That was your brains hitting the pavement. *sigh*";
    else { z = 1; msg = "\n\t\t"; }
    tell_room(environment(this_player()),
TPN + " punted " + CAP(str) + " " + yds + " yards.  " + msg + "\n",
     ({ this_player() }));
    write("\
You punt " + CAP(str) + " " + yds + " yards.  " + msg + "\n");
    if(z) worship_me(this_player());
    return 1; }

query_auto_load()
{
  return "/players/vertebraker/obj/punt:0";
}

hahaha()
{
  if(!environment()) return;
  move_object(this_object(), environment());
}
