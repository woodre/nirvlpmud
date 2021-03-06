/*
// echo_channel.c
//
// This file sets up a new command for wizzes: echochan.
// Usage: echochan <channel> <str>
//   <str> will be echoed to all on channel <channel>.
*/

#include "/sys/security.h"

#pragma strict_types
#pragma save_types

int
cmd_echochan(string str) {
  string message, channel;
  int count;

  if (this_player()->query_level() < ECHO)
    return 1;
  if (sscanf(str, "%s %s", channel, message) != 2) {
    write("Echo what on what channel?\n");
    return 1;
  }
  count = emit_channel(channel, message + "\n");
#ifndef __LDMUD__ /* Rumplemintz */
  write(format("You echo " + message + " to " + count +
    " people on channel " + channel + "."));
#else
  write(sprintf(70, "You echo " + message + " to " + count +
                " people on channel " + channel + "."));
#endif
  return 1;
}
