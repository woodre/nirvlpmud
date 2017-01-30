inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("flash"))  {
MOCO("/players/jenny/dukes/mobs/flash.c"),this_object()); }
    if(arg) return;
    set_light(1);
short_desc=(BOLD+""+BLU+"Hazzard County Sheriff's office"+NORM);
long_desc=
"This is the office of Sheriff Rosco P. Coltrane.  It is much smaller\n"+
"than the County Commissioner's office.  A desk and chair sit in\n"+
"the back of the room, next to the window.  There is a CB radio\n"+
"on top of the desk.\n";
items = ({
"chair","Flash often sleeps on this chair",
"desk","This solid oak desk belongs to Rosco",
"cb","A CB which lets Rosco communicate with his deputies",
"radio","A CB which lets Rosco communicate with his deputies",
"window","This window overlooks Hazzard Square",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/boffice1","east",
});
}
