inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
short_desc=(BOLD+""+BLU+"Hazzard County jail"+NORM);
long_desc=
"This is the Hazzard County jail.  Wanted criminals, and the Dukes\n"+
"are often locked up here.  The cement floor gives this place a\n"+
"cold feel.  The deputies desk sits in the middle of the room, right\n"+
"in front of the holding cell.  A staircase leads back up to the\n"+
"courthouse building.\n";
items = ({
"floor","This is just a plain cement floor",
"desk","Cleetus sometimes falls asleep at this desk while the Duke boys escape",
"cell","The Duke boys have been in this cell more times than a pig's been in slop",
"staircase","This takes you back upstairs",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/boffice1","up",
});
}
