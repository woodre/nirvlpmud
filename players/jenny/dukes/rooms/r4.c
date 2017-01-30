inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
#include "/players/jenny/dukes/general.h"
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You find tire marks on the pavement."+NORM+"\n");
short_desc=(""+BOLD+"Hazzard Town Square"+NORM+"");
long_desc=
"This here is a quiet little street that runs through the heart\n"+
"of Hazard.  Taking a gander around this small country town,\n"+
"you notice a quaint little park to the west.  A run down\n"+
"garage is to the east.\n";
items = ({
"garage","Cooter's garage is a dirty, run down white building",
"street","This street is part of Hazzard Square",
"park","This is a small park in the center of the town square",
"marks","These marks were left here by the General Lee",
"tire marks","These marks were left here by the General Lee",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r3","north",
 "/players/jenny/dukes/rooms/r5","south",
 "/players/jenny/dukes/rooms/garage","east",
});
}
