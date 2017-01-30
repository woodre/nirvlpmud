#include "../def.h"

status main(string str, object PO, object User)
{
  string mee;
  string nam;
  
  if(!str) str = "";

  if(str != "") 
  {
    nam = (string)User->QN;

    if(sscanf(str,"e %s", mee)) 
      str = RED+"("+BLU+"] "+NORM+nam + " " + mee;

    else if(sscanf(str,"a %s",mee)) 
      str = RED+"("+BLU+"] "+NORM+mee + " <" + nam + ">";

    else str = RED+"("+BLU+"] "+NORM+ nam +" intones:"+ str;
      str = format(str,70);
  }
  call_other(ROOT+"obj/chandaem.c","speak_channel", str);
  return 1; 
}
