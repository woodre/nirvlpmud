#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string file;
  file = DIR+"log/personal/"+(string)User->query_real_name();
  if(file_size(file) > 0)
    tail(file);
  else
    TOU "You do not have anything in your personal log yet.\n");
  return 1;
}

