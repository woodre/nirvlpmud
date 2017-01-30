inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("hughie hogg"))  {
MOCO("/players/jenny/dukes/mobs/hughie.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice a secret compartment in the floor."+NORM);
short_desc=(BOLD+""+WHT+"Boss Hogg's office"+NORM);
long_desc=
"This is Boss Hogg's private office in the backroom of his\n"+
"restaurant.  He uses it for his shady deals.  The plush red\n"+
"carpet feels nice to stand on.  A pool table sits near the\n"+
"back of the room, and Boss Hogg's desk is not far from it.\n"+
"A barber chair sits in front of the desk.\n";
items = ({
"chair","Boss Hogg loves nothing more than to sit in this chair and\n"+
"eat a plate full of raw liver",
"desk","An oak desk that belongs to Boss Hogg",
"table","A small pool table",
"carpet","This red carpet looks expensive",
"compartment","Boss Hogg uses this compartment to hide the real county ledger\n"+
"That is the one that shows how much money he stole",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/nest1","out",
});
}
