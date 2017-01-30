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
"you notice a quaint little park to the northeast.  The road to\n"+
"the south leads to the Boar's Nest.\n";
items = ({
"park","This is a small park in the center of the town square",
"road","A small dirt and gravel road that heads south",
"street","This street is part of Hazzard Square",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r8","north",
 "/players/jenny/dukes/rooms/r9","south",
 "/players/jenny/dukes/rooms/r6","east",
});
}
