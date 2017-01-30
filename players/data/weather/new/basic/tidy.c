/*
 * basic/tidy.c - an inherit class for selfdestructing items
 *
 */

#pragma strong_types

#include <message.h>
#include <prop/room.h>

varargs mixed query_property(string key, string item);  // Coogan, 18-Oct-2000

int clean_up(int arg) {
  if (arg > 1)
    return 0;
  if (__FILE__ == program_name())
    return 0;
  if (query_property(P_NO_CLEANUP))
    return 0;
  if (environment())
    send_message(({ M_ROOM, environment(), "Not used for a long time, ",
                    M_ME_THE, M_ME_VERB, "scrumble", " to dust." }));
  while (first_inventory())
    destruct(first_inventory());
  destruct(this_object());
  return 0;
}

