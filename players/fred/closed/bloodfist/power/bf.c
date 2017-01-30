#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object *all, it;
  int a,sa;
  string msg,b,c;
  if(!str) return 0;
  else if(str == "muffle")
  {
    if(PO->toggle_bf_chan_muffle())
      TOU "You muffle the guild channel.\n");
    else
      TOU "You unmuffle the guild channel.\n");
  }
  else if(PO->query_bf_chan_muffle())
    return (notify_fail("The guild channel is muffled.\n"), 0);
  else if(str == "history")
    CHAN_DAEMON->print_history(User, 1);
  else if(str == "history reset" && User->query_level() >= 60)
    CHAN_DAEMON->reset_history(User, 1);
  else if(str == "mon")
    CHAN_DAEMON->print(User,str,2);
  else if(sscanf(str, "invite %s", b))
  {
    if(it = find_player(b))
    {
      if(it->query_invis())
        TOU "That player is not logged in.\n");
      else if(present("bloodfist_gob_chan", it) ||
        present("bloodfist_gob", it))
        TOU "That player is already on the channel.\n");
      else {
        object in;
        in = clone_object("/players/fred/closed/bloodfist/obj/chan_obj.c");
        CHAN_DAEMON->print(User, capitalize((string)User->query_real_name())+
          " invites "+capitalize(b)+" to join the channel.",3);
        move_object(in, it);
        in->join();
      }
    }
    else
      TOU "That player is not logged in.\n");
  }
  else if(sscanf(str, "kick %s", b))
  {
    if(it = find_player(b))
    {
      if(present("bloodfist_gob_chan", it))
      {
        if(it->query_level() >= 21)
          TOU "You cannot kick a wizard from the channel.\n");
        else if(!present("bloodfist_gob_chan", it)->qk())
          TOU "That player is not on the channel.\n");
        else {
          CHAN_DAEMON->print(User,capitalize((string)User->query_real_name())+
          " kicks "+capitalize(b)+" from the channel.",3);
          present("bloodfist_gob_chan", it)->dest();
        }
      }
      else {
        if(present("bloodfist_gob", it) && !User->query_invis())
          TOU "That player can not be kicked from the channel.\n");
        else if(present("bloodfist_gob", it) && User->query_level() > 20)
          TOU "That player is not logged in.\n");
        else
          TOU "That player can not be kicked from the channel.\n");
        return 1;
      }
    }
    else
      TOU "That player is not logged in.\n");
  }
  else if(sscanf(str, ":%s", b))
  {
    string em, arg, file;
    
    if(sscanf(b, "%s %s", em, arg) != 2) {
      em = b;
    }
    em = implode(explode(em, "."), "");
    if(file_size(file="/bin/soul/_"+em+".c") > 0) {
      return (int)file->guildcast("bloodfist", arg);
    }
    CHAN_DAEMON->print(User, b,2);
  }
  else
    CHAN_DAEMON->print(User, str,1);
  return 1;
}

