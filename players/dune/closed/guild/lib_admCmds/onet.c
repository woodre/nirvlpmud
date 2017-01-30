#include "../DEFS.h"

status main(string str)
{
/* Officer channel */
  object everyone, member;
  int i;

  if (!IPTP->guild_officer()) return 0;
  if (!str)
  {
    write("Usage: onet <message>.\n");
    return 1;
  }
  if (str == "history")
  {
    call_other(CHANNELD, "viewhistory", "onet");
    return 1;
  }
  call_other(CHANNELD, "otell", str);
  return 1;
}
