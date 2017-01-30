
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("out", "northeast");
     add_action("out", "south");
     add_action("out", "northwest");
     add_action("up", "up");
}

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="gate"||str=="walls") { \
          write("The walls of glistening adamantite and sturdy gates look"+\
             "\nwell able to thwart any would-be invaders.\n"); \
          return; } \
     if(str=="spires") { \
          write("You notice the colorful banners or several wizards\n"+ \
                "flying from them.\n"); \
          return; }

FOUR_EXIT("players/bastion/antaria/citadel/gate2", "north",
     "players/bastion/antaria/citadel/eastroad", "northeast",
     "players/bastion/antaria/selebrand/wizroad1", "south",
     "players/bastion/antaria/citadel/westroad", "northwest",
     "Citadel Gate",
     "You stand before a mighty citadel. Beyond the high surrounding wall,\n"+
     "you see the marble spires and gold domes of the Wizards' City. Guards\n"+
     "stand at attention aside the twenty-foot bronze gates, keeping a\n"+
     "watchful eye on the crowds and caravans that bustle through the\n"+
     "entryway. A road leads around the citadel, going northeast and\n"+
     "northwest, while the wizard's road leads south. You note a shimmering\n"+
     "disturbance in the air above you <up>.\n",
     1)

id(str) { return str=="spires" || str=="walls" || str=="gate"; }

out() {
     write("A voice chimes in your ear, 'The wizard's citadel is closed\n"+
           "to foreigners at this time.'\n");
     return 1;
}

up() {
     write("You enter the drifting plane of limbo...\n");
     this_player()->move_player("away#players/bastion/room/limbo");
     return 1;
}
