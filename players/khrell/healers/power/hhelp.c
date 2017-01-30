#include "../def.h"

status main(string str, object PO, object User)
{
  string doc;

  if(!str) 
    doc = "general"; 
  else 
    doc = str;
  
  write("\n");
   cat("/"+ROOT+"docs/help/"+doc);
  write("\n");

  return 1; 
}
