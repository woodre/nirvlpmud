#include "../DEFS.h"

status main(string str) {
/* Guild daemon channel */
  object everyone, member;
  int i;

  if (!str)
  {
    write("Usage: mnet <message>.\n");
    return 1;
  }

  if (str == "history")
  {
    call_other(CHANNELD, "viewhistory", "mnet");
    return 1;
  }

  if (!IPTP->guild_officer())
  {
    write("Only guild officers may write on this channel.\n");
    return 1;
  }

  call_other(CHANNELD, "overchannel", str);
  return 1;
}
