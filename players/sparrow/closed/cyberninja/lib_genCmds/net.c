#include "../DEFS.h"

status main(string str) {
/* Guild channel */
  if(IPTP->query_nohonor() && TP->query_level() < 20)
  {
    write("As a Renegade, you may not interact over the Net.\n");
    return 1;
  }
  if(!str)
  {
    write("Usage: net <message>\n");
    return 1;
  }
  if(str == "history")
  {
    call_other(CHANNELD, "viewhistory", "net");
    return 1;
  }
  call_other(CHANNELD, "tell", str);
  return 1;
}
