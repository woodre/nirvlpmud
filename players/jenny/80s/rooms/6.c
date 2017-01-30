inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("et"))  {
MOCO("/players/jenny/80s/mobs/et.c"),this_object()); }
    if(arg) return;
    set_light(0);
set_smell(BOLD+"You can smell the beer which has been spilt."+NORM);
set_search(BOLD+"You notice a trail of candy."+NORM);
long_desc=
"This is the kitchen of a modest home.  The room is lit only by the\n"+
"moonlight coming in though the windows.  This place is a mess,\n"+
"because the refrigerator has been raided, and food is spilled all over\n"+
"the floor.  It looks like someone, or something, was very hungry.  A\n"+
"trail of candy leads off into another room.\n";
short_desc=(WHT+"A house"+NORM);
items = ({
"cans","These are empty beer cans, which have been carelessly left on the floor",
"candy","This is a trail of Reese's pieces, which leads off into Elliot's bedroom",
"moonlight","The soft moonlight provides the room with a little bit of light",
"windows","The windows are open, as are the curtains",
"curtains","White curtains, which seem to glisten in the moonlight",
"food","The food has been spilled all over the floor.  There are a few empty\n"+
              "beer cans as well",
"beer","It has been spilled all over the floor",
"refrigerator","A white refrigerator.  The door has been left open",
});
dest_dir = ({
 "/players/jenny/80s/rooms/12","out",
});
}
