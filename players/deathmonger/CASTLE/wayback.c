#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
ONE_EXIT("players/deathmonger/CASTLE/peabody","west",
         "You have entered the wayback machine",
         "You have entered the Way-Back Machine.  I hope you will help\n"+
         "me design this by mailing me in the post office..\n",
1)
