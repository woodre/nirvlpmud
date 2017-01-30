#include "/players/feldegast/closed/guild/defines.h"

do_command() {
  CHANNEL->remove_member(this_player());
  return 0;
}
