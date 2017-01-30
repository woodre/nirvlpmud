inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
set_no_clean(1);
if(!present("chicken")) {
MOCO("/players/jenny/dukes/mobs/chicken.c"),this_object()); 
MOCO("/players/jenny/dukes/mobs/chicken.c"),this_object()); 
MOCO("/players/jenny/dukes/mobs/chicken.c"),this_object()); }

if(!present("chicken 3") && !present("chicken 2") && present("chicken"))  {
MOCO("/players/jenny/dukes/mobs/chicken.c"),this_object()); 
MOCO("/players/jenny/dukes/mobs/chicken.c"),this_object()); }

if(!present("chicken 3") && present("chicken 2"))  {
MOCO("/players/jenny/dukes/mobs/chicken.c"),this_object()); }

if(!present("goat")) {
MOCO("/players/jenny/dukes/mobs/goat.c"),this_object()); }
    if(arg) return;
    set_light(1);
    set_smell(BOLD+"The nearby animals leave an unpleasant smell."+NORM);
    set_search(BOLD+"You notice all sorts of farm equipment laying around."+NORM);
short_desc=(BOLD+""+RED+"The Duke's barn"+NORM);
long_desc=
"This old barn is where the Dukes store their farm equipment.\n"+
"When the door is open, many of the animals roam in and out.\n"+
"Bales of hay are stacked near the center.  This barn is\n"+
"sometimes used to hide the General Lee from Rosco, when the\n"+
"Duke boys don't want him to know they are home.\n";
items = ({
"equipment","You notice a plow, bags of seed, and several pitchforks",
"hay","Bales of hay, stacked very high",
"door","A wooden door",
"bales","Bales of hay, stacked very high",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/farm2","out",
});
}
