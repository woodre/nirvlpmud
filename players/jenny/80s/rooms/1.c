inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("michael milken"))  {
MOCO("/players/jenny/80s/mobs/milken.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice a crystal chandelier hanging from the ceiling."+NORM);
long_desc=
"This luxurious home belongs to Michael Milken.  Even the entrance\n"+
"hallway to this mansion is impressive.  The floor is made of marble,\n"+
"and gives a palace like feel.  Antique vases are placed on pedestals\n"+
"throughout the hallway, and a magnificent spiral staircase leads to\n"+
"the upstairs balcony.  \n";
short_desc=(HIY+BOLD+"The Milken's House"+NORM);
items = ({
"vases","Michael Milken bought these expensive vases with money\n"+
                   "he earned selling junk bonds",
"pedestals","Stylish gold plated pedestals used to display the vases",
"floor","The floor is made of marble.  It makes the room feel cold",
"staircase","This grand marble staircase leads to the upstairs balcony",
"balcony","A balcony which overlooks the entrance hallway",
"chandelier","A beautiful crystal chandelier which hangs from the ceiling",
});
dest_dir = ({
 "/players/jenny/80s/rooms/2","out",
});
}
