#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena NW" + NORM;
   long_desc = BOLD + "------\n" + "|             " + NORM + GRY + " The Northwest corner of \n" + NORM + BOLD + "| " + NORM + CYN + "NE" + NORM + YEL + " --    " + NORM + GRY + "    the testing arena.\n" + NORM + BOLD + "|\n" + NORM + YEL + "  |  \\\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena2", "east",
                 "/players/llew/Other/rooms/test_arena5", "southeast",
                 "/players/llew/Other/rooms/test_arena4", "south",
              });
   set_light(1);
}
