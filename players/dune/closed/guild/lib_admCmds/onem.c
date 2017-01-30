#include "../DEFS.h"

status main(string str)
{
/* Officer channel emote */
  if (!IPTP->guild_officer()) return 0;
  if(!str)
  {
    write("Usage: onem <emote>\n");
    return 1;
  }
  call_other(CHANNELD, "oemote", str);
  return 1;
}
