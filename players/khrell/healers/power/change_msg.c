#include "../def.h"

status main(string str, object PO, object User)
{
  if(!str)
  {
    write("What would you like to change your entrance msg to?\n");
    return 1;
  }
  
  write("You have changed your entrance msg to:\n"+
        str+".\n");
  PO->set_enter_msg(str);

  SOE;
  return 1; 
}
