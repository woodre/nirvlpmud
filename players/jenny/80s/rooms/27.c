inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("bill cosby"))  {
MOCO("/players/jenny/80s/mobs/cosby.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice a sweater thrown over the back of a chair."+NORM);
long_desc=
"This is the living room of a home belonging to Bill Cosby.  A\n"+
"colorful Persian rug partially covers the hardwood floor, and the\n"+
"walls are decorated with quite a few autographed pictures.  The\n"+
"room is furnished by two black leather couches, a matching black\n"+
"leather chair, and a grand piano.\n";
short_desc=(HIR+"The Cosby Residence"+NORM);
items = ({
"sweater","One of the many colorful sweaters that Bill is fond of wearing",
"walls","The walls are painted white, and decorated with many autographed pictures",
"pictures","Autographed pictures of some of Bill's favorite jazz musicians",
"rug","An expensive looking Persian rug.  It is very colorful",
"floor","The dark hardwood floor looks very beautiful",
"couches","Two black leather couches.  They look comfortable",
"chair","A black leather reclining chair.  It looks very comfortable",
"piano","A beautiful grand piano.  It is rarely used",
});
dest_dir = ({
 "/players/jenny/80s/rooms/26","out",
});
}
