inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("michael j fox"))  {
MOCO("/players/jenny/80s/mobs/mfox.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some markings on the wall."+NORM);
set_smell(BOLD+"Smells like lemon pledge."+NORM);
long_desc=
"This is the kitchen of a home belonging to Michael J. Fox.  The blue\n"+
"ceramic tile floor is spotless, as are the white counter tops.  Glass\n"+
"cabinets, high on the walls, hold the fine china.  There is a refrigerator,\n"+
"stove, microwave, as well as other miscellaneous appliances.  A sliding\n"+
"glass door leads outside onto the deck.\n";
short_desc=(HIB+"The Fox Residence"+NORM);
items = ({
"markings","This is where Michael measures himself every day, hoping to grow a little bit",
"walls","The walls are covered with wallpaper.  It is white with blue patterns.\n"+
           "One of the walls has some markings on it",
"floor","The floor is made up dark blue ceramic tiles.  It is spotless",
"cabinets","These are glass cabinets, with pretty patterns etched into them",
"china","Expensive white china with gold trim",
"counter tops","The spotless white counter tops encircle the kitchen",
"refrigerator","A brand new refrigerator",
"stove","A new gas stove.  It has either been cleaned recently, or is rarely used",
"microwave","A big microwave oven",
"appliances","There is a blender, toaster, and electric can opener",
"door","A sliding glass door, which leads out onto the deck and gives a\n"+
             "view of the yard",
"yard","A beautifully landscaped yard with many trees and flower beds.\n"+
            "Some lawn darts were left in the middle of the yard",
"deck","A beautiful wood deck.  There is a large gas grill sitting on it",
"blender","This is a glass blender.  Michael often uses it for mixed drinks",
"can opener","An ordinary, white electric can opener, which is sitting on the counter",
"toaster","A shiny metal toaster.  It holds four slices of bread",
"grill","This is a large gas grill, powered by a propane tank",
"propane tank","A large white tank, which is attached to the bottom of the grill",
});
dest_dir = ({
 "/players/jenny/80s/rooms/26","out",
});
}
