inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You notice the Bundy's house.  Do you dare enter?"+NORM+"\n");
short_desc=("A residential street.");
long_desc=
"This is a somewhat quiet residential street.  The traffic\n"+
"has thinned out considerably.  There are modest homes on\n"+
"each side of the street, and small trees scattered about.\n"+
"The house to the east belongs to the Bundy's.\n";

items = ({
"homes","All of these homes are nicer than Al Bundy's house",
"street","A pothole infested residential street",
"trees","Small trees.  With leaves",
"house","This house belongs to the Bundy's.  You could enter it",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/3b","south",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("house","enter");
}
house(arg) { 
if(!arg) { return 0; }
if(arg == "house") {
write("You walk into the Bundy's house.\n");
TP->move_player("into the house#players/jenny/bundy/rooms/hb3.c");
return 1; }
}
