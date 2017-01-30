inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("cooter davenport"))  {
MOCO("/players/jenny/dukes/mobs/cooter.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_smell(""+BOLD+"This place smells of grease and gasoline."+NORM+"\n");
set_search(""+BOLD+"You notice some tools laying about."+NORM+"\n");
short_desc=(""+BOLD+"Cooter's Garage"+NORM+"");
long_desc=
"This old garage sure aint much to look at.  There is dirt and\n"+
"grease everywhere.  Tools are laying all over the place, and\n"+
"a wrecked car sits on blocks near the center.  Even though\n"+
"this place looks like a dump, it still gets plenty of business,\n"+
"courtesy of the Duke Boys and the Hazzard County Sheriff's\n"+
"Department.  No place in town does a better job of fixing cars.\n";
items = ({
"dirt","Dirt is everywhere, Cooter never cleans this place",
"grease","Grease is everywhere, Cooter never cleans this place",
"car","This is a wrecked police car, curtsey of Rosco's bad driving",
"tools","Wrenches and screwdrivers are scattered about",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r4","out",
});
}
