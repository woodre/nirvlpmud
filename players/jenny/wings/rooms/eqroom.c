/* note to self - maybe when you search, find a box of pucks, tape, or something. */
inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int justone;
realm() { return "NT"; }
reset(arg) {
justone = 1;
if(!present("paul boyer"))  {
MOCO("/players/jenny/wings/mobs/staff/boyer.c"),TO); }
    if(arg) return;
    set_light(1);
long_desc=
"This is a large storage room where the team keeps equipment.  It has\n"+      
"a cement floor, and plain white walls.  Four rows of shelving units take\n"+
"up most of the room.  There is a large rack by the door, which holds\n"+
"hundreds of hockey sticks, and a large workbench farther towards\n"+
"the back.\n";
items = ({
"rack","This is a large metal rack, which is holding hundreds of hockey\n"+
            "sticks.  It is divided into many different spaces, each having a\n"+
             "players name written above it",
"sticks","Hundreds of hockey sticks are stored in the rack",
"floor","A plain grey cement floor",
"walls","Plain white walls with no decorations whatsoever",
"workbench","A large wooden workbench.  There is a skate sharpener,\n"+
                       "and a hot air gun sitting on it",
"boxes","Boxes of pucks, tape, pads, jerseys, and other equipment",
"skate sharpener","A metal machine with a grinding wheel attached to it",
"hot air gun","A small black device which looks like a small hair dryer.  Players\n"+
                     "use this when working on their sticks",
"shelving units","Large metal shelves with boxes of equipment on them",
"equipment","Boxes of pucks, tape, pads, jerseys, and other equipment",
"shelving","Large metal shelves with boxes of equipment on them",
"sharpener","A metal machine with a grinding wheel attached to it",
});
dest_dir = ({
 "/players/jenny/wings/rooms/locker1","out",
});
}
short() {
return BOLD+RED+"Equipment Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
     add_action("getpucks","search");
}
getpucks() {
if(present("paul boyer")) {write("Paul Boyer says:  I can't let you search around here.  Scotty wouldn't like that.\n"); return 1;}
if(justone > 1) { return 0; }
 if(!this_player()->add_weight(1)) {
    write("You find a box on one of the shelving units, but are already\n"+
              "carrying too much stuff to grab it.\n");
return 1; }

MOCO("/players/jenny/wings/items/puckbox.c"),TP);
write("You find a cardboard box on one of the shelving units.\n");
justone = 2;
return 1;}
