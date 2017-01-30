#include "../x.h"

int cmd_loginmsg(string str)
{
 if(!str)
 {
  if(PO->query_login_msg())
   write("Your current loginmsg looks like:\n\n"+
  "  "+HIY+"*"+NORM+(string)PO->query_login_msg()+"\n");
  else write("No current loginmsg set.\nType 'loginmsg <msg>'\n");
  return 1;
 }
 write("Ok, loginmsg set!\n");
 PO->set_login_msg(str);
 cmd_loginmsg(0);
 return 1;
}
