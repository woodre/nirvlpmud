#define ERROR_LOG "/players/grimm/closed/LOGS/board_errors"
#define BOARD_NAME "players/grimm/closed/obj/badge_stuff/bboard2"
#include "/players/grimm/closed/obj/badge_stuff/board.h"
 
reset(arg) {
        if (arg)
                if (!random(5)) {
                        say("A small 'ganger appears and secures some " +
                        "notes on the board that were loose.\n");
                        say("The 'ganger leaves again.\n");
                }
}
