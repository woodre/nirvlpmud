#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  TOU "Saving your guild stats...\n");
  PO->advance_checks();
  PO->save_stats();
  return 1;
}
