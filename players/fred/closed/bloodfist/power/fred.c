#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  if(!str) return 0;
  write_file("/players/fred/closed/bloodfist/log/bugs",
    ctime()[4..15]+" "+Name+" ("+file_name(environment(User))+"):\n"+
    str+"\n\n");
  TOU "You write in the bug log: "+str+".\n");
  TRU Name+" scrawls something on a piece of paper for Fred.\n", ({ User }));
  return 1;
}
