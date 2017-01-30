#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena N" + NORM;
   long_desc = BOLD + "-------\n" +GRY + "               The Northern area of \n"  + NORM + YEL + "-- " + CYN + "N" + YEL + " -- " + GRY + "       the testing arena.\n"  + NORM + YEL + "       \n" + "/  |  \\\n\n"+ NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena3", "east",
                 "/players/llew/Other/rooms/test_arena6", "southeast",
                 "/players/llew/Other/rooms/test_arena5", "south",
                 "/players/llew/Other/rooms/test_arena4", "southwest",
                 "/players/llew/Other/rooms/test_arena1", "west",
              });
   set_light(1);
}
