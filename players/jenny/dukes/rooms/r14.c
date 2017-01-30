inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("sheriff little"))  {
MOCO("/players/jenny/dukes/mobs/little.c"),this_object()); }
    if(arg) return;
    set_light(1);
short_desc=(BOLD+"Chickasaw County Line"+NORM);
long_desc=
"You have come to the county line.  This bridge over\n"+
"Miller's Creek separates Hazard and Chickasaw Counties.\n"+
"Chickasaw County is the domain of Sheriff Little.  Not\n"+
"many people look forward to going there, but it is one\n"+
"of the few ways out of Hazzard.\n";
items = ({
"bridge","This bridge is used to cross Miller's Creek.  The Duke boys have been\n"+
"known to just jump the creek instead",
"creek","One of the small creeks that wind their way through Hazard County",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r13","south",
 "/players/jenny/areaentrance","leave",
});
}
