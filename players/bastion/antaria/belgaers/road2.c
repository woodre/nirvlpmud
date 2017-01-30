
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("up", "up");
}

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object sign;
     if(!present("sign")) {
          sign=clone_object("obj/treasure");
          sign->set_id("sign");
          sign->set_short("a sign");
          sign->set_long("The sign reads:\n\n"+
                         "    Harrowers Way: west \n");
          sign->set_read("Try looking at it\n");
          sign->set_weight(10000);
          move_object(sign, this_object());
     }
}


ONE_EXIT(
     "players/bastion/antaria/belgaers/road3", "west",
     "Crossroads",
     "You stand at a crossroads in a thick wood. Roads leads in the cardinal\n"+     "directions. Above you, you note a shimmering disturbance in the air <up>.\n",
     1)

up() {
     write("You enter the drifting plane of limbo...\n");
     this_player()->move_player("away#players/bastion/room/limbo");
     return 1;
}
