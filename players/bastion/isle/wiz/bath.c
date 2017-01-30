
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

ONE_EXIT("players/bastion/isle/wiz/up_hall1", "west",
     "Bathroom",
     "You enter a spacious bathroom. The decorating motif seems to be blue\n"+
     "marble. A pool, recessed into the floor with steps leading into it,\n"+
     "is apparently for bathing. A comode, vanity stand and sink are the\n"+
     "other prominent features of the room.\n",
     1)

flush() {
     tell_room(this_object(), "Whoosh!\n");
     return 1;
}

id(str) { return str=="toilet" || str=="commode"; }
