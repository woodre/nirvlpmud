inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int path;
reset(arg) {
#include "/players/jenny/dukes/general.h"
path = random(4);
    if(arg) return;
    set_light(1);
short_desc=(BOLD+"Old Ridge Road"+NORM);
long_desc=
"You are on a small dirt road, which winds through northern\n"+
"Hazzard County.  There are lots of oak, cottonwood, and\n"+
"willow trees on each side of the road.  Members of the\n"+
"Old Time Ridgerunner Association used to use back roads\n"+
"like this to run moonshine.\n";
items = ({
"trees","These here trees have been in Hazzard County for 100 years",
"road","An old dirt road",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/dr2","northeast",
 "/players/jenny/dukes/rooms/r12","southwest",
});
}
init() { 
    ::init();
add_action("findpath","search");
add_action("path","follow");
}
findpath(arg)  {
if(path == 2) {
write(BOLD+"You notice a path leading into the woods.  You could follow the path."+NORM+"\n");
return 1; }}
path(arg) {
if(path == 2) {
TP->move_player("through the path#players/jenny/dukes/rooms/still.c");
return 1; }
}
