#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena E" + NORM;
   long_desc = YEL + " \\  | " + NORM + BOLD + " |\n" + "       |     " + GRY + "  The Eastern area of\n" + NORM + YEL + "-- " + CYN + " E " + NORM + BOLD + " | " + GRY + "      the testing arena.\n" + NORM + BOLD + "       |\n" + NORM + YEL + " /  | " + NORM + BOLD + " |\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena3", "north",
                 "/players/llew/Other/rooms/test_arena9", "south",
                 "/players/llew/Other/rooms/test_arena8", "southwest",
                 "/players/llew/Other/rooms/test_arena5", "west",
                 "/players/llew/Other/rooms/test_arena2", "northwest",
              });
   set_light(1);
}
