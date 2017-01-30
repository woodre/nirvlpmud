inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
short_desc=(BOLD+""+WHT+"Hazzard County Courthouse"+NORM);
long_desc=
"This is the Hazzard County Court House.  Many different county\n"+
"offices are located in this building.  The entrance way where\n"+
"you are standing looks pretty plain, except for the portrait on\n"+
"the wall.  The courtroom is to the north of here, while the county\n"+
"commissioner's office is to the east.  Sheriff Coltrane's office\n"+
"is to the west, and a stairway leads down to the jail.\n";
items = ({
"courtroom","Court can only be held when the circuit judge is in\n"+
"town.  It is closed right now",
"portrait","A portrait of J.D. Hogg",
"stairway","This leads down to the jail",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/roscooffice","west",
 "/players/jenny/dukes/rooms/hoggoffice","east",
 "/players/jenny/dukes/rooms/jail","down",
 "/players/jenny/dukes/rooms/r8","out",
});
}
