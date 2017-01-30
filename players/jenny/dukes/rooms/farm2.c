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
    if(arg) return;
    set_light(1);
    set_smell(BOLD+"The nearby animals leave an unpleasant smell."+NORM);
    set_listen(BOLD+"You hear the chickens scrambling for food.  They seem as happy\n"+
    "as Boss Hogg at Thanksgiving dinner."+NORM);
short_desc=(BOLD+""+WHT+"The Duke Farm"+NORM);
long_desc=
"This small farm belongs to the Duke family.  It has been\n"+
"Duke land for over 100 years.  A white rundown farm\n"+
"house sits to the southeast, and a red barn can be seen to\n"+
"the north.  A split rail fence runs along this end of the\n"+
"property.  Chickens seem to roam freely within the yard.\n";
items = ({
"house","The Duke family has lived in this house for a long time",
"barn","The Dukes store all of their farm equipment in here.\n"+
"You could 'enter' the barn",
"chickens","The Dukes use these chickens for both laying eggs, and fried chicken dinner",
"fence","This fence could use another coat of whitewash.  I reckon Bo and Luke\n"+
"would have time for it, if Rosco would ever give them a moments peace",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/farm1","south",
});
}
init() { 
    ::init(); 
add_action("barn","enter");
}
barn(arg) { 
if(!arg) { return 0; }
if(arg == "barn")  {
TP->move_player("into the barn#players/jenny/dukes/rooms/barn.c");
return 1; }
}
