#include "../defs.h"

status main(string str, object PO, object User)
{
  if(!str)
  {
    TOU "What are you trying to report?\n");
    return 1;
  }

  write_file(FIXES,
   User->QN+" reported from:\n"+
   file_name(environment(User))+"\n"+
    ""+str+"\n\n");

  TOU "Thanks!\n");

  return 1;
}
