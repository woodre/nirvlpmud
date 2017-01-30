#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena SE" + NORM;
   long_desc = YEL + " \\  |\n" + NORM + BOLD + "      |  " + GRY + "      The Southeast corner of\n" + NORM + YEL + "--" + CYN + " SE " + NORM + BOLD + "| " + GRY + "       the testing arena.\n" + NORM + BOLD + "      |\n" + " ------\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena6", "north",
                 "/players/llew/Other/rooms/test_arena8", "west",
                 "/players/llew/Other/rooms/test_arena5", "northwest",
              });
   set_light(1);
}
