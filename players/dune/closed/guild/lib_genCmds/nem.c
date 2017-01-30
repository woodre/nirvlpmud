#include "../DEFS.h"

status main(string str) {
/* Guild channel emote */
  if(IPTP->query_nohonor() && TP->query_level() < 20) {
    write("As a Renegade, you may not interact over the Net.\n");
    return 1; }
  if(!str) {
    write("Usage: nem <emote>\n");
    return 1;
  }
  call_other(CHANNELD,"emote",str);
  return 1;
}

