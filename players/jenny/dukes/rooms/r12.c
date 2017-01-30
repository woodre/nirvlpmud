inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
short_desc=(BOLD+"Old Mill Road"+NORM);
long_desc=
"This is a small dirt road heading out towards Chickasaw\n"+
"County.  Lots of tall oak and willow trees are growing\n"+
"on both sides of the road.  Members of the Old Time\n"+
"Ridgerunner Association used to use back roads like this\n"+
"to run moonshine.\n";
items = ({
"trees","These here trees have been in Hazzard County for 100 years",
"road","An old dirt road",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r13","north",
 "/players/jenny/dukes/rooms/dr1","northeast",
 "/players/jenny/dukes/rooms/r11","south",
});
}
