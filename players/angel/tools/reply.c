/* Reply code stolen courtesy of Verte's in /bin/play/_reply.c
 * Thanks, Verte :)
*/

#include "defs.h"

int main(string arg) {
  string to;

  if (!stringp(to = (string)this_player()->Replyer()))
    return (notify_fail("Nobody to reply to :(\n"), 0);

  if (!arg)
    return (notify_fail("Tell what to " + capitalize(to) +"?\n"), 0);

  return (int)(call_other(BIN+"tell","main",to+" "+arg));
}

