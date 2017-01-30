#include <ansi.h>
inherit "/players/vertebraker/closed/std/m_efuns";
#define ALLOWED ({ "daranath", "maledicta", "wocket", "feldegast", "vertebraker", "softly" })
#define MASTER "/players/vertebraker/exp/master"

string
short()
{
    return "A gigantic vidscreen [" + BOLD + "ExpRace" + NORM + "]";
}

status
id(string str)
{
    return (str == "vidscreen" || str == "screen" ||
            str == "gigantic vidscreen");
}

void
long()
{
    int d;
    object x;

    write("\
A humongous, thirty-five foot tall video screen.\n\
It is currently " + ((d = (status)MASTER->query_activated()) ? 
                     "activated" : "deactivated") + ".\n");
    if(d)
    {
      write("\
You can '" + BOLD + "view" + NORM + "' the current status.\n");
      if(this_player() &&
        !MASTER->query_registered((string)this_player()->query_name()))
        write("You can '" + BOLD + "register" + NORM + "' for the \
experience contest.\n");
    }
    write("\
Type 'alltime' for a list of all exp races.\n");
    if((x = this_player()) && (int)x->query_level() > 21)
      write("\
You can '" + BOLD + (d ? "deactivate" : "activate") + NORM + "' the vidscreen.\n\
To see the prizes to give for everyone, type '" + BOLD + "prizes" + NORM + "'.\n");
}

void
init()
{
    add_action("cmd_alltime", "alltime");
    add_action("cmd_view", "view");
    add_action("cmd_activate", "activate");
    add_action("cmd_deactivate", "deactivate");
    add_action("cmd_prizes", "prizes");
    add_action("cmd_register", "register");
}

status
cmd_register()
{
    string x;

    if(!MASTER->query_activated()) return 0;
    if((status)MASTER->query_registered((string)this_player()->query_name()))
    {
      notify_fail("You are already registered for the Xp Race.\n");
      return 0;
    }
    write("You register yourself for the Experience Race.\n");
    say((x = (string)this_player()->query_name()) + " registers for the \
Experience Race.\n");
    MASTER->register(x);
    return 1;
}

status
cmd_view()
{
    int i, rnk, s;
    mixed *d;
    string rx;

    if(!MASTER->query_activated())
    {
      notify_fail("The vidscreen is blank.\n");
      return 0;
    }
s = sizeof(d = (mixed *)MASTER->get_top("unlim"));

    write(BOLD + "\n\t]]]]]] " + HIW + "Top Players: Experience Race" + NORM + BOLD + " [[[[[\n\n" + NORM);

    for(i = 0; i < s; i += 2)
    {
      rnk ++;
      rx = ""+rnk;
    if(rnk < 10) rx = (" " + rx);
      write("\t   " + rx + ": " + pad(d[i], 19) + d[i + 1] + "\n");
    }
    
    write(BOLD + "\n\t]]]]]]]]]]]]]]]]]]]]][[[[[[[[[[[[[[[[[[\n\n" + NORM);
    return 1;
}

status
cmd_alltime()
{
    int i, x, r, rank, s;
    string rx;
    mixed *g, *AllTime;

    write("Top 3 Rankings Per Date:\n\n");
    s = sizeof(AllTime = (mixed *)MASTER->get_alltime());
    for(i = 0; i < s; i += 2)
    {
      write(BOLD + AllTime[i] + NORM + "\n");
      r = sizeof(g = AllTime[i + 1]);
      rank = 1;
      for(x = 0; x < r; x += 2, rank ++)
      {
        rx = pad("" + rank + ": ", 4);
        write("\t" + rx + pad(g[x], 14) + "" + g[x+1] + "\n");
      }
    }

    return 1;
}

status
cmd_activate()
{
    if((int)this_player()->query_level() < 21 ||
       !this_player()->is_player() || member_array((string)this_player()->query_real_name(), ALLOWED) == -1)
      return 0;
    if((status)MASTER->query_activated())
    {
      notify_fail("The vidscreen has already been activated!\n");
      return 0;
    }
    write("You activate the vidscreen.\n");
    say((string)this_player()->query_name() + " \
activates the vidscreen.\n");
    write("CONTEST IS NOW ONLINE!\n");
    MASTER->activate();
    return 1;
}

status
cmd_deactivate()
{
    if((int)this_player()->query_level() < 21 ||
       !this_player()->is_player() || member_array((string)this_player()->query_real_name(), ALLOWED) == -1)
      return 0;
    if(!MASTER->query_activated())
    {
      notify_fail("The vidscreen is not activated!\n");
      return 0;
    }
    write("You deactivate the vidscreen.\n");
    say((string)this_player()->query_name() + " \
deactivates the vidscreen.\n");
    MASTER->deactivate();
    write("Contest Shutdown.\nType 'prizes' for a printout.\n");
    return 1;
}

status
cmd_prizes()
{
    int i, s, g, bonus;
    mapping m;
    mixed *h;

    if((int)this_player()->query_level() < 21 ||
       !this_player()->is_player())
      return 0;

    if((status)MASTER->query_activated())
    {
      notify_fail("The vidscreen must be deactivated.\n");
      return 0;
    }
    h = m_values(m = (mapping)MASTER->query_mapping());
    h = sort_array(h, "sort_me", this_object());
    s = sizeof(h); 
    for(i = 0; i < s; i ++)
    {
      g ++;
      if(g < 4)
        switch(g)
        {
          case 1:
            bonus = 50;
            break;
          case 2:
            bonus = 40;
            break;
          case 3:
            bonus = 30;
            break;
        }
      else bonus = 25;
      bonus = ((h[i] * bonus) / 100);
      if(h[i])
        write(pad(get_key(m, h[i]), 20) + "" + bonus + "\n");
    }
    return 1;
}

int
sort_me(int a, int b)
{
    return(b > a);
} 
