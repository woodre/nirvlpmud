inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
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
    set_listen(BOLD+"You hear the chickens scrambling for food.  They seem as happy\n"+
    "as Boss Hogg at Thanksgiving dinner."+NORM);
short_desc=(BOLD+""+WHT+"The Duke Farm"+NORM);
long_desc=
"This small farm belongs to the Duke family.  It has been\n"+
"Duke land for over 100 years.  A white rundown farm\n"+
"house sits to the east, and a red barn can be seen on the\n"+
"north end of the property.  Chickens seem to roam freely\n"+
"within the yard.\n";
items = ({
"house","The Duke family has lived in this house for generations",
"barn","This faded barn could use a new coat of paint",
"chickens","The Dukes use these chickens for both laying eggs, and fried chicken dinner",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/farm2","north",
 "/players/jenny/dukes/rooms/dr2","west",
 "/players/jenny/dukes/rooms/farmhouse","enter",
});
}
