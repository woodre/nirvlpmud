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
"you notice a quaint little park to the southwest.  A fire\n"+
"hydrant sits to the east.  Rumor has it, those trouble making\n"+
"Dukes live north of here.\n";
items = ({
"park","This is a small park in the center of the town square",
"street","This street is part of Hazzard Square",
"hydrant","This is a fake red fire hydrant.  Rosco often places it here after\n"+
"people park their cars, then writes them a ticket",
"fire hydrant","This is a fake red fire hydrant.  Rosco often places it here after\n"+
"people park their cars, then writes them a ticket",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r11","north",
 "/players/jenny/dukes/rooms/r4","south",
 "/players/jenny/dukes/rooms/r2","west",
});
}
