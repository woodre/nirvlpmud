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
"you notice a quaint little park to the northwest.  A parking\n"+
"meter sits to the east.\n";
items = ({
"park","This is a small park in the center of the town square",
"meter","This meter runs notoriously fast",
"parking meter","This meter runs notoriously fast",
"street","This street is part of Hazzard Square",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r4","north",
 "/players/jenny/dukes/rooms/r6","west",
});
}
