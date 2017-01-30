#include "defs.h"

status
main(string arg)
{
  CHANNELD->channel_msg(GD_FORMAT+capitalize((string)this_player()->query_real_name())+" has left the game.\n");
  return 0;
}
