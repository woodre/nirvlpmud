#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string all;
  int heh;
  all = "/players/fred/closed/bloodfist/log/bugs";
  while(cat(all, heh, 20) != 0)
   heh += 20;
  write("\n");
  return 1;
}
