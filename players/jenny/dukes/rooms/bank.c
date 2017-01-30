inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("lu lu hogg"))  {
MOCO("/players/jenny/dukes/mobs/lulu.c"),this_object()); }
if(!present("maybell"))  {
MOCO("/players/jenny/dukes/mobs/maybell.c"),this_object()); }
    if(arg) return;
    set_light(1);
short_desc=(BOLD+""+YEL+"Hazzard Bank"+NORM);
long_desc=
"This is the Hazzard Bank.  It is owned by Boss Hogg.  This\n"+
"bank owns the mortgages on ninety percent of the land in\n"+
"Hazzard County.  There are tellers counting money behind\n"+
"the counter.\n";
items = ({
"tellers","These tellers are ready to assist you with your banking needs",
"counter","A long counter which separates the tellers from the customers",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r1","out",
});
}
