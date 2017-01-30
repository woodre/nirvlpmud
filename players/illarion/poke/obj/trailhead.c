/* trailhead.c -- additional 'castle' type object for entrance to my second
 * area.  It's pretty much a dummy object, existing just to give a short,
 * long, and the add_action to enter it.
 * Illarion 29 Feb 2000
 */
#include "/players/illarion/dfns.h"

id(str) { return str=="trail"; }
short() {
   return "A steep trail down the north side of the plateau";
}
long() {
   write("This steep but stable-looking trail cuts down the north side of\n"+
         "the plateau, quickly disappearing from sight.  Although steep,\n"+
         "it appears to be a stable climb down, for those that wish to\n"+
         BLD("descend")+" the trail.\n");
}
init() {
   add_action("cmd_descend","descend");
}
cmd_descend(str) {
   if(str != "trail") return 0;
   write("You carefully descend the trail to the base of the plateau.\n");
   this_player()->move_player("down the trail#"+PROOM+"ontrail");
   return 1;
}
