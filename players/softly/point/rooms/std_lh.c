
#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";
reset(arg) {
   if(arg) return;
   short_desc=(RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint " + HIY + "Light" + NORM + "house");
   set_light(0);
   set_chance(7);
   add_msg("The cold wind whistles through the area...");
   add_msg("Something wet and cold brushes against you....");
   add_msg("You can hear the sounds of the sea slapping against the rocks.....");
   add_msg("Leeeaaaavvvvveee ttthhhhiiiiisssss pppllllaaacccceeee....");
   add_msg("The walls seem to close in around you....");
   add_msg("There is no treasure here!  Leave at once!");
   add_msg("The curved staircase creaks and shudders.");
   add_listen("main","You hear the sound of the sea crashing on the rocks.");

}


