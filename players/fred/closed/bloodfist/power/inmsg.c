#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string cur;
  if(PO->is_testchar())
    TOU "Test characters cannot change their login or logout messages.\n");
  else if(!str)
  {
    cur = (string)PO->query_inmsg();
    if(!cur)
      TOU "You don't currently have a custom login message set.\n");
    else
      TOU "Your current login message is:\n"+cur+"\n");
  }
  else if(str)
  {
    if(str == "|")
    {
      TOU "You reset your custom login message to the default.\n");
      PO->set_inmsg(0);
    }
    else {
      TOU "You set your custom login message to:\n"+str+"\n");
      PO->set_inmsg(str);
    }
  }
  return 1;
}
