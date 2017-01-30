#include "../defs.h"

inherit WAXFUNS;

status
main(string arg)
{
  if (!arg)
  {
    tail(MYWLOG);
    return 1;
  }

  arg = capitalize(arg)+".";
  write_file(MYWLOG, HIK+date_time()+NORM+NORM+": "+arg+"\n");
  write("Entry added to your log:\n"+HIK+date_time()+NORM+NORM+": "+arg+"\n");
  return 1;
}
