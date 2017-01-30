inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int justone;
realm() { return "NT"; }
reset(arg) {
justone = 1;
if(!present("linesmen"))  {
MOCO("/players/jenny/wings/mobs/other/linesman2.c"),TO); 
MOCO("/players/jenny/wings/mobs/other/linesman1.c"),TO); }
if(!present("referee"))  {
MOCO("/players/jenny/wings/mobs/other/ref2.c"),TO); 
MOCO("/players/jenny/wings/mobs/other/ref1.c"),TO); }
    if(arg) return;
    set_light(1);
long_desc=
"This is a small dressing room that is used by on-ice officials.  The\n"+      
"walls are plain white, and the floor is mostly covered by a large\n"+
"black rug.  There are two dressing stalls on each side of the room\n"+
"and benches in front of them.  A water cooler sits in the back of\n"+
"the room.\n";
items = ({
"cooler","A refrigerated water cooler, with a large 5 gallon jug on top",
"water cooler","A refrigerated water cooler, with a large 5 gallon jug on top",
"floor","The cement floor is mostly covered by a large black rug",
"rug","A large black rug with a white circle in the middle and the NHL logo\n"+
          "inside of it",
"logo","A black logo, kinda shaped like a badge, with the letters NHL\n"+
            "written diagonally",
"walls","Plain white walls with no decorations whatsoever",
"stalls","There are four stalls total.  Each one is like a big open locker.\n"+
             "There is a rack and some hangers, along with a shelf above them",
"rack","A metal bar with some hangers hanging from it",
"hangers","There are four wooden hangers in each stall",
"shelf","Each stall has a wooden shelf for setting personal belongings",
"benches","A long wooden bench is in front of each set of stalls",
});
dest_dir = ({
 "/players/jenny/wings/rooms/i4","out",
});
}
short() {
return BOLD+RED+"Referee's Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
     add_action("getwhistle","search");
}
getwhistle() {
if(justone > 1) { return 0; }
 if(!this_player()->add_weight(1)) {
    write("You search the stalls and find a whistle on one of the shelves, but\n"+
              "are already carrying too much stuff to grab it.\n");
return 1; }

MOCO("/players/jenny/wings/items/whistle.c"),TP);
write("You search the stalls and find a whistle on one of the shelves.\n");
justone = 2;
return 1;}
