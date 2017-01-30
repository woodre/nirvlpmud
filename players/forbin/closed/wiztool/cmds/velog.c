/* workreport viewing command */

#include "/players/forbin/define.h"

status main(string who) {
  write("\n");
  return command("more /log/WR/"+who+"_workreport", this_player());
}
