#include "../def.h"

status main(string str, object PO, object User)
{
  write("Your entrance msg is: "+PO->query_enter_msg()+".\n");
  return 1; 
}
