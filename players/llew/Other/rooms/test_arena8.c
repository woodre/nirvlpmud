#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;
   short_desc = BOLD + "Test Arena S" + NORM;
   long_desc = YEL + "\\  |  /\n" + GRY + "               The Southern area of\n" + NORM + YEL + "--" + CYN + " S " + YEL + "-- " + GRY + "       the testing arena.\n\n" + NORM + BOLD + "-------\n\n" + NORM;
   dest_dir = ({ "/players/llew/Other/rooms/test_arena5", "north",
                 "/players/llew/Other/rooms/test_arena6", "northeast",
                 "/players/llew/Other/rooms/test_arena9", "east",
                 "/players/llew/Other/rooms/test_arena7", "west",
                 "/players/llew/Other/rooms/test_arena4", "northwest",
              });
   set_light(1);
}
