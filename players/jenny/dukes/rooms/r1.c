inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
short_desc=(BOLD+"Hazzard Town Square"+NORM);
long_desc=
"This here is a quiet little street that runs through the heart\n"+
"of Hazard.  Taking a gander around this small country town,\n"+
"you notice a quaint little park to the southeast.  The bank\n"+
"is to the north.\n";
items = ({
"park","This is a small park in the center of the town square",
"street","This street is part of Hazzard Square",
"bank","This bank is owned by Boss Hogg.  You could 'enter' it",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r8","south",
 "/players/jenny/dukes/rooms/r2","east",
});
}
init() { 
    ::init(); 
add_action("bank","enter");
add_action("bank2","north");
add_action("bank2","n");
}
bank(arg) { 
if(!arg) { return 0; }
if(arg == "bank")  {
TP->move_player("into the post office#players/jenny/dukes/rooms/bank.c");
return 1; }
}
bank2(arg) { 
TP->move_player("into the bank#players/jenny/dukes/rooms/bank.c");
return 1; }
