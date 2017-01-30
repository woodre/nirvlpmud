#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string cur;
  if(PO->is_testchar())
     TOU "Test characters cannot change their login or logout messages.\n");
  else if(!str)
  {
    cur = (string)PO->query_outmsg();
    if(!cur)
      TOU "You don't currently have a custom logout message set.\n");
    else
      TOU "Your current logout message is:\n"+cur+"\n");
  }
  else if(str)
  {
    if(str == "|")
    {
      TOU "You reset your custom logout message to the default.\n");
      PO->set_outmsg(0);
    }
    else {
      TOU "You set your custom logout message to:\n"+str+"\n");
      PO->set_outmsg(str);
    }
  }
  return 1;
}

