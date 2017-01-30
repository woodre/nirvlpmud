inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
short_desc=(""+BOLD+"Hazzard Town Square"+NORM+"");
long_desc=
"This here is a quiet little street that runs through the heart\n"+
"of Hazard.  Taking a gander around this small country town,\n"+
"you notice a quaint little park to the north.  The post office\n"+
"is to the south.\n";
items = ({
"park","This is a small park in the center of the town square",
"street","This street is part of Hazzard Square",
"post office","The people of Hazard come here for their mail\n"+
"You could 'enter' it",
"office","The people of Hazard come here for their mail.\n"+
"You could 'enter' it",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r7","west",
 "/players/jenny/dukes/rooms/r5","east",
});
}
init() { 
    ::init(); 
add_action("office","enter");
add_action("office2","south");
add_action("office2","s");
}
office(arg) { 
if(!arg) { return 0; }
if(arg == "office")  {
TP->move_player("into the post office#players/jenny/dukes/rooms/post.c");
return 1; }
}
office2(arg) { 
TP->move_player("into the post office#players/jenny/dukes/rooms/post.c");
return 1; }
