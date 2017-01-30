#include "../def.h"

status main(string str, object PO, object User)
{
  if(!PO->query_reduced()) 
  {
    PO->set_reduced(1);
    write("Need Mon set to reduced mode.\n");
  } 

  else 
  {
    PO->set_reduced(0);
    write("Need Mon set to full mode.\n");
  }
  return 1;
}
