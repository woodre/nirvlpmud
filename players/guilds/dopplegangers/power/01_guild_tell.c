/*
 * Guild Channel
 *
 * Rumplemintz
 */

#include <ansi.h>
#include "../def.h"


int main(string str) {
  string pre, chan;

  if (!str) return 0;

  switch(this_player()->query_guild_rank()) {
    case 1..19:   pre = HIW;
    case 20..49:  pre = RED;
    case 50..999: pre = HIB;
    default:      pre = HIR;
  }

  switch(query_verb()) {
    case "mt": case "mystic_tell":
      chan = "dopplegangersM";
      pre += "[(D)Mystics] ";
      break;
    case "bt": case "barbarian_tell":
      chan = "dopplegangersB";
      pre += "[(D)Barbarians] ";
      break;
    case "ct": case "commander_tell":
      chan = "dopplegangers";
      pre += "[Commander] ";
      break;
    default:
      chan = "dopplegangers";
      pre += "[Dopples] ";
      break;
  }
  if (str[0] == ':')  /* It's an emote, different prefix */
    pre += NORM;
  else
    pre += this_player()->query_name() + ": " + NORM;
  if (str == "list" || str == "history" || str == "who")
    CHAND->channel_message(chan, str);
  else
    CHAND->channel_message(chan, str, pre);
  return 1;
}
