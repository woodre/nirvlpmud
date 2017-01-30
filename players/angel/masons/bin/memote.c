#include "../defs.h"

status main(string arg)
{
  if (!arg) {
    write("What is it you wanted to emote?  \n");
  return 1;
  }

  CHANNELD->channel_message(CHAN, "<Masons> "+(string)this_player()->query_name()+" "+arg+"\n");
  return 1;
}
