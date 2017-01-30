#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena W" + NORM;
   long_desc = BOLD + "|" + NORM + YEL + "  |  /\n" + NORM + BOLD + "|    " + GRY + "          The Western area of\n" + NORM + BOLD + "|" + NORM + CYN + "  W " + YEL + " -- " + GRY + "      the testing arena.\n" + NORM + BOLD + "|\n" + "| " + NORM + YEL + " |  \\\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena1", "north",
                 "/players/llew/Other/rooms/test_arena2", "northeast",
                 "/players/llew/Other/rooms/test_arena5", "east",
                 "/players/llew/Other/rooms/test_arena8", "southeast",
                 "/players/llew/Other/rooms/test_arena7", "south",
              });
   set_light(1);
}
