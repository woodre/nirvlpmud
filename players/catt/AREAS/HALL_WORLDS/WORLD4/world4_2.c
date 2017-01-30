#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
              }
ONE_EXIT("players/wendy/MAZE/maze","northeast",
         "world4_2",
  "You feel a little disoriented as you find yourself in an\n"+
   "old roman shrine of baucus, the god of wine. The place is\n"+
   "very quiet and no one is in the main temple room that you\n"+
   "found yourself in. The alter, however, is covered completely\n"+
   "in deep red and bright green grapes and other odd assortments.\n"+
   "You feel that the followers of baucus are preparing some kind\n"+
   "of ritual offering to their god. Who knows what they may have\n"+
   "instore?\n", 1)
