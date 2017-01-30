inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You notice the D'Arcy's house.  Maybe you should check it out."+NORM+"\n");
short_desc=("A residential street.");
long_desc=
"This is a somewhat quiet residential street.  The traffic\n"+
"has thinned out considerably.  There are modest homes on\n"+
"each side of the street, and small trees scattered about.\n"+
"The house to the east belongs to the D'Arcy's.\n";

items = ({
"homes","All of these homes are nicer than Al Bundy's house",
"street","A pothole infested residential street",
"trees","Small trees.  With leaves",
"house","This house belongs to the D'Arcy's.  You could enter it",
});
dest_dir = ({
"/players/jenny/bundy/rooms/3a","north",
 "/players/jenny/bundy/rooms/3c","south",
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
write("You walk into the D'Arcy's house.\n");
TP->move_player("into the house#players/jenny/bundy/rooms/4b.c");
return 1; }
}
