#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  The city of Celestia was once a thriving, majestic city located in\n"+
 "the heart of the Celestial Plains.  Now the city lies in ruins, having\n"+
 "been abandoned years ago.  The cobblestone road that once supported\n"+
 "bustling traffic in and out of the city is now abandoned.  Weeds grow\n"+
 "across the road, leaving many of the stones cracked and crumbled. What\n"+
 "was once a majestic archway guarding the city, now stands weathered\n"+
 "and crumbling, having suffered years of neglect and pounding from the\n"+
 "harsh weather of the plains.  Rusted hinges hang from the stone sides\n"+
 "of the archway, the gates having been looted years ago.\n");
add_item("hinges","Badly rusted and pitted hinges");
add_item("archway","Once a magestic work of architecture, the stones are crumbling and weathered now");
add_item("blah","blah blah blah");
add_exit(PLAIN+"r2.c","north");
add_exit(PLAIN+"p3.c","southwest");
}
}
