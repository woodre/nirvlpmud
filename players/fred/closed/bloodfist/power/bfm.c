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
    CHAN_DAEMON->print_history(User, 2);
  else if(str == "history reset" && User->query_level() >= 60)
    CHAN_DAEMON->reset_history(User, 2);
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
    CHAN_DAEMON->bfm(User, b,2);
  }
  else
    CHAN_DAEMON->bfm(User, str, 1);
  return 1;
}

