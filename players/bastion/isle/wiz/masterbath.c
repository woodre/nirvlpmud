
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("flush", "flush");
}

#undef EXTRA_LONG
#define EXTRA_LONG \
     if((str=="commode") || (str=="toilet")) { \
          write("It is cool and porcelain.\n"); \
          return; }

ONE_EXIT("players/bastion/isle/wiz/bedroom", "north",
     "Bathroom",
     "You enter a small bathroom. The decorating motif seems to be blue\n"+
     "marble. A tub is to south, a stall for showering next to it. A\n"+
     "commode, vanity stand and sink are here, a shaving kit left near\n"+
     "the sink.\n",
     1)

flush() {
     tell_room(this_object(), "Whoosh!\n");
     return 1;
}

id(str) { return str=="toilet" || str=="commode"; }
