#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string msg, string channel)
{
  CHANNEL->query_history(channel);
  return 1;
}
