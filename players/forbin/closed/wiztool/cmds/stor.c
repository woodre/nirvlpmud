#include "/players/forbin/define.h"

status main(string arg) {
  if(!arg) {
    notify_fail("Check whose storage?\n");
      return 0;
  }
  write(BOLD + "\tLocker storage:\n" + NORM);
  command("cat /players/catwoman/storage/" + arg, this_player());
  write(BOLD + "\tHotel storage:\n" + NORM);
  command("cat /players/boltar/hotel/room/" + arg + ".o", this_player());
}
