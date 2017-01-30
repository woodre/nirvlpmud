#include "../defs.h"

void reset(int arg)
{
  if(!arg)
    CHANNEL->add_channel("Crystal", CYN+"*"+HIB+"Crystal"+NORM+CYN+"* "+NORM, 4);
}

int do_cmd(string str)
{
  if(!str)
  {
    notify_fail("What do you want to communicate?\n"); 
    return 1; 
  }
  if(str[0]==':')
    CHANNEL->broadcast("Crystal", TP->query_name()+" "+str[1..strlen(str)]);
  else
    CHANNEL->broadcast("Crystal", TP->query_name()+" says: "+str);
  return 1;
}
