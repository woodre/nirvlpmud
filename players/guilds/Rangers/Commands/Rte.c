#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string msg, string channel)
{
  object *rangers;
  int i;
  string format, em, arg, file;
  if(!msg)
  {
    tell_object(this_player(),
      "Zordon tells you: \"It is better to say something.\"\n");
    return 1;
  }
  format = BOLD + BLUE + "[" + OFF + GREEN + channel + OFF + BOLD + BLUE +
    "] " + OFF + "";
  if(sscanf(msg, "%s %s", em, arg) != 2)
  {
    em = msg;
  }
  em = implode(explode(em, "."), "");
  if(file_size(file="/bin/soul/_" + em + ".c") > 0)
  {
    return (int)file->guildcast("rangers", arg);
  }
  format += (string) this_player()->query_name();
  format += " " + msg + "\n";
  CHANNEL->channel_message(channel, format);
  return 1;
}
