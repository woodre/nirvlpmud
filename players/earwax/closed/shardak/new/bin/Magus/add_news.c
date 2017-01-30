#include "../defs.h"

inherit WAXFUNS;

status
main(string arg)
{
  string date;

  if (!arg)
  {
    notify_fail("Syntax: add_news message.\n");
    return 0;
  }

  date = date_time();
  date = HIK+date[0..8]+NORM+NORM+date[9..13];
  arg = " "+HIK+"<"+HIR+capitalize((string)this_player()->query_real_name())+HIK+">"+NORM+NORM+": "+capitalize(arg)+"\n";
  write_file(NEWS, HIK+date+NORM+NORM+arg);
  write("Added to news: \n"+HIK+date+NORM+NORM+arg+"\n");
  return 1;
}
