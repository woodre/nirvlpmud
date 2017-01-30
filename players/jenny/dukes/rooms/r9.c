inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
short_desc=(BOLD+"Stone Creek Road"+NORM);
long_desc=
"This small dirt and gravel road heads out towards the southern\n"+
"end of Hazard county.  There are cottonwood, oak, and willow\n"+
"trees on both sides of the road.  Miller's Pond can be seen to\n"+
"the west, and old man Peabody's barn is to the east.\n";
items = ({
"trees","These trees have been in Hazzard county for over 100 years",
"road","An old dirt and gravel road",
"barn","Cletus once crashed his patrol car into this barn.  Boss Hogg docked him\n"+ "a months pay for repairs",
"pond","The Duke boys often jump this pond in the General Lee\n"+
"Rosco, Enos, and Cletus usually land somewhere in the middle",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r7","north",
 "/players/jenny/dukes/rooms/r10","south",
});
}
