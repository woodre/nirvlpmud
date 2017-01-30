#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena SW" + NORM;
   long_desc = YEL + "  |  /\n" + NORM + BOLD + "|         " + GRY + "     The Southwest corner of\n" + NORM + BOLD + "| " + NORM + CYN + "SW" + YEL + " -- " + GRY + "       the testing arena.\n" + NORM + BOLD + "|\n" + "------\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena4", "north",
                 "/players/llew/Other/rooms/test_arena5", "northeast",
                 "/players/llew/Other/rooms/test_arena8", "east",
              });
   set_light(1);
}
