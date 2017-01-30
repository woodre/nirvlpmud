#define ERROR_LOG "/players/guilds/dopplegangers/log/board_errors"
#define BOARD_NAME "players/guilds/dopplegangers/log/iboard"
#include "/players/guilds/dopplegangers/obj/gboard.h"
 
reset(arg) {
  if (arg)
    if (!random(5)) {
      say("A small 'ganger appears and secures some " +
          "notes on the board that were loose.\n");
      say("The 'ganger leaves again.\n");
    }
}
