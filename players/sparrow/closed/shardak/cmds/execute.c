#include "../macros.h"
#include "../def.h"
#include "../people.h"

object heh;

status main(string arg)
{
    if(previous_object()->GuildClass() < C_MASTER)
      return 0;

    else
    {
      object ob;

    if(!arg) return 0;
      heh = 0;

      if(!(ob = find_player(arg)) || (int)ob->query_level() > 21)
      {
        notify_fail("Player isn't online.\n");
        return 0;
      }
      if((string)ob->query_guild_name() != GUILDNAME)
      {
        notify_fail("That player isn't a Shardak.\n");
        return 0;
      }
      if(servant(ob) && ((int)servant(ob)->GuildClass() > servant(this_player())->GuildClass()))
        return (notify_fail("You may not execute someone of a higher class than you.\n"), 0);

/*
      write("execute is disabled.\n");
      return 1;
*/

      write("\
You have chosen to execute " + (string)ob->query_name() + ".\n\
Are you SURE you want to do this?  Abuse is not good...\n\
[y/n] ");
      heh = ob;
      input_to("confirm");
    }
      return 1;
}

status
confirm(string arg)
{
    if(arg != "y")
      write("Wise choice.\n");
    else
    {
      object myenv, corpse;
      if(!heh || !environment(heh))
      {
        heh = 0;
        write("You've waited too long.\n");
        return 1;
      }
      if(heh->query_ghost())
      {
        heh = 0;
        write("They're already dead.\n");
        return 1;
      }
      myenv = environment(this_player());
      move_object(this_player(), environment(heh));
      heh->attacked_by(this_player());
      write("Shardak funnels his death energy into " +
      (string)heh->query_name() + "!\n");
      tell_object(heh, "\
Shardak focuses his death energy into you.\n");
      heh->death();
      CHANNELD->broadcast((string)heh->query_name() + 
      " has been executed by " + (string)this_player()->query_name() + ".\n",
        1, "{Servants}");
      write_file(LOGDIR + "execute",
ctime()[4..15] + " " +
(string)this_player()->query_real_name() + " executed " + 
(string)heh->query_real_name() + ".\n");
      if(corpse = present("corpse", environment(heh)))
      {
        write("You take the corpse.\n");
        move_object(corpse, this_player());
      }
      heh = 0;
      move_object(this_player(), myenv);
      return 1;
    }
}
