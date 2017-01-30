#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

#define COLORS ({RED, BLUE, BOLD+BLUE, BOLD+RED, GREEN, YELLOW, MAGENTA, REV_BLUE, BOLD+BLACK, CYAN, WHITE, })

status
RangerPower(string msg, string channel)
{
  int i;
  string format;
  string Border;
  string Main;
  i = random(sizeof(COLORS));
  Border = COLORS[i];
  i = random(sizeof(COLORS));
  Main = COLORS[i];
  if(!msg)
  { 
    tell_object(this_player(),
      "Zordon tells you: \"It is better to say something.\"\n");
    return 1;
  }
  format =  Border + "[" + OFF + Main + channel + OFF + Border + "]" +
            OFF + " ";
  format += previous_object()->QRangerAnsi() + this_player()->query_name() +
            OFF + " says:";
  format += " " + msg + "\n";
  CHANNEL->channel_message(channel, format);
  return 1;
}
