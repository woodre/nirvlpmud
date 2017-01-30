#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena NE" + NORM;
   long_desc = BOLD + " ------\n" + "      |       " + GRY + " The Northeast corner of \n" + NORM + YEL + "-- " + CYN + "NW" + NORM + BOLD + " |" + GRY + "        the testing arena.\n" + NORM + BOLD + "      |\n" + NORM + YEL + " /  |\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena6", "south",
                 "/players/llew/Other/rooms/test_arena5", "southwest",
                 "/players/llew/Other/rooms/test_arena2", "west",
              });
   set_light(1);
}
