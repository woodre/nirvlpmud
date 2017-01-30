
#include "std.h"
int is_here;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("west", "west");
}

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object ob;
     ob=present("troll");
     if(ob) {
          move_object(ob, "/players/bastion/room/void");
          destruct(ob);
          tell_room(this_object(), "The troll leaves.\n");
     }
     is_here=0;
     return 1;
}

TWO_EXIT("players/bastion/antaria/belgaers/road8", "east",
     "players/bastion/antaria/belgaers/road10", "west",
     "Bridge",
     "A bridge crosses a foaming river here. Spray washes through\n"+
     "the rocks below.\n",
     1)

west() {
     object ob;
     if(is_here && !present("troll")) return;
     if(present("troll")) return;
     ob=clone_object("players/bastion/monster/troll");
     move_object(ob, this_object());
     tell_room(this_object(), "A troll climbs from underneath the bridge.\n");
     is_here=1;
     return 1;
}
