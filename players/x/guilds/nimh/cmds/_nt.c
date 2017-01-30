#include "../x.h"

int cmd_nt(string str)
{
 if(PO->query_chan_muffle())
 {
  write("Type 'ntm' to turn your muffle off.\n");
  return 1;
 }
 if(!str || ((str[0] == ':' || str[0] == '>') && strlen(str) < 2))
  return 0;
 return (int)MASTER->broadcast(str);
}
