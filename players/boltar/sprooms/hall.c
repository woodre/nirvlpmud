#include "std.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
money = clone_object("obj/money");
    if (!money || !present(money)) {
call_other(money, "set_money", 25000);
    }

}
TWO_EXIT("players/boltar/workroom.c", "east",
   "players/boltar/lv2/pawnstorage.c", "north",
 "The hall   ",
 "Hallway outside Boltar's workroom.\n", 1)
