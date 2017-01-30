#include "../defs.h"

status main(string str, object PO, object User)
{
  if(!str)
  {
    TOU "Emote what?\n");
    return 1;
  }
  if(PO->query_venomed())
  {
    TRU BOLD+CAP((string)PO->query_symbiote())+" "+str+NORM+"\n");
    return 1;
  }
  TRU User->QN+" "+str+"\n");
  return 1;
}
