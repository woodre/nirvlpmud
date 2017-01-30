inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
short_desc=("A residential street.");
long_desc=
"This is a somewhat quiet residential street.  The traffic\n"+
"has thinned out considerably.  There are modest homes on\n"+
"each side of the street, and small trees scattered about.\n";
items = ({
"homes","All of these homes are nicer than Al Bundy's house",
"trees","Small trees.  With leaves",
"street","A pothole infested residential street",
});
dest_dir = ({
"/players/jenny/bundy/rooms/3c","north",
 "/players/jenny/bundy/rooms/3e","south",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
