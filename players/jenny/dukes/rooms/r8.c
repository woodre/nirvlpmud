inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some tire marks on the pavement"+NORM);
short_desc=(BOLD+"Hazzard Town Square"+NORM);
long_desc=
"This here is a quiet little street that runs through the heart\n"+
"of Hazard.  Taking a gander around this small country town,\n"+
"you notice a quaint little park to the east.  The county\n"+
"commissioners' office and jail are to the west.\n";
items = ({
"street","This street is part of Hazzard Square",
"park","This is a small park in the center of the town square",
"jail","This is where the bad guys, and the Dukes, get locked up",
"office","This is Boss Hogg's office",
"marks","These marks were left here by the General Lee",
"tire marks","These marks were left here by the General Lee",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r1","north",
 "/players/jenny/dukes/rooms/r7","south",
 "/players/jenny/dukes/rooms/boffice1","west",
});
}
