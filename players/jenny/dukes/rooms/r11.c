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
"on both sides of the road, and there is a big mud puddle\n"+
"right in the middle.  Members of the Old Time Ridgerunner\n"+
"Association used to use back roads like this to run\n"+
"moonshine.\n";
items = ({
"road","An old dirt road",
"trees","These here trees have been in Hazzard County for 100 years",
"puddle","This mud puddle is known as the Hazzard County car wash",
"mud puddle","This mud puddle is known as the Hazzard County car wash",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r12","north",
 "/players/jenny/dukes/rooms/r3","south",
});
}
