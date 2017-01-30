inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some tire marks"+NORM);
short_desc=(BOLD+"Stone Creek Road"+NORM);
long_desc=
"This small dirt and gravel road heads out towards the southern\n"+
"end of Hazard county.  There are cottonwood, oak, and willow\n"+
"trees on both sides of the road.  A huge oak tree stands\n"+
"majestically to the west.  The Boar's Nest east of here.\n";  
items = ({
"oak tree","Rosco once managed to get his patrol car stuck up on one\n"+
"of the limbs",
"tire marks","These marks were left here by the General Lee",
"road","An old dirt and gravel road",
"boar's nest","This here is the most popular restaurant in Hazzard County",
"marks","These marks were left here by the General Lee",
"trees","These trees have been in hazard county for over 100 years",
"tree","Rosco once managed to get his patrol car stuck up on one\n"+
"of the limbs",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r9","north",
 "/players/jenny/dukes/rooms/nest1","east",
 "/players/jenny/areaentrance","leave",
});
}
