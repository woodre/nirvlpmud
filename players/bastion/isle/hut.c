
#include "std.h"

#undef EXTRA_LONG
#define EXTRA_LONG\
     if(str=="hut") { \
          write("It is a simple, thatched hut.\n"); \
          return; \
}

TWO_EXIT("players/bastion/isle/grass2", "west",
     "players/bastion/isle/hut_inner", "enter",
     "Hut",
     "A small hut stands here enclosed on three sides by native rock. You\n"+
     "hear some activity from within. A breeze escapes the tossing grass\n"+
     "to the west.\n",
     1)
