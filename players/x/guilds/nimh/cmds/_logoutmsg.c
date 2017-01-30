#include "../x.h"

int cmd_logoutmsg(string str)
{
 if(!str)
 {
  if(PO->query_logout_msg())
   write("Your current logoutmsg looks like:\n\n"+
  "  "+HIY+"*"+NORM+(string)PO->query_logout_msg()+"\n");
  else write("No current logoutmsg set.\nType 'logoutmsg <msg>'\n");
  return 1;
 }
 write("Ok, logoutmsg set!\n");
 PO->set_logout_msg(str);
 cmd_logoutmsg(0);
 return 1;
}
