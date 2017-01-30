#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena C" + NORM;
   long_desc = YEL + " \\  |  /\n" + GRY + "               The Center of\n" + NORM + YEL + "-- " + CYN + " C " + YEL + " -- " + GRY + "     the testing arena.\n\n" + NORM + YEL + " /  |  \\\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena2", "north",
                 "/players/llew/Other/rooms/test_arena3", "northeast",
                 "/players/llew/Other/rooms/test_arena6", "east",
                 "/players/llew/Other/rooms/test_arena9", "southeast",
                 "/players/llew/Other/rooms/test_arena8", "south",
                 "/players/llew/Other/rooms/test_arena7", "southwest",
                 "/players/llew/Other/rooms/test_arena4", "west",
                 "/players/llew/Other/rooms/test_arena1", "northwest",
              });
   set_light(1);
}
