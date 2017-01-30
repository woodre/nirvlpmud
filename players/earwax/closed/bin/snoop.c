/*
 * Just a personal log of snoops I initiate.
 * Useless because snoop is actioned by wiz_soul.
 */

#include "../defs.h"

inherit WAXFUNS;

status main(string arg)
{
  if (!arg) write_file(SNOOP_LOG, date_time()+": Ended snoop.\n");
  else write_file(SNOOP_LOG, date_time()+": "+arg+".\n");

  return 0;
}
