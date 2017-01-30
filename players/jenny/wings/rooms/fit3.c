inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("ward"))  {
if(random(100) < 38) {
MOCO("/players/jenny/wings/mobs/players/ward.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice a rack along the wall containing many\n"+
                                    "sets of dumbells."+NORM);
     set_smell(BOLD+"The smell of sweat hangs in the air."+NORM);
long_desc=
"This is the fitness room inside of Joe Louis Arena.  It is used\n"+      
"by the Red Wing players to help maintain peak physical condition.\n"+
"It is pretty big, and can be used by many players at once.  The\n"+
"thin red carpet is unstained and looks fairly new.  The walls are\n"+
"painted white, with pictures all around the room.  This section\n"+
"of the room has lots of weightlifting equipment.\n";
items = ({
"carpet","This thin red carpet was just put in last year",
"walls","The walls are painted white, and have pictures on them",
"pictures","These are pictures of Detroit's Stanley Cup winning teams.\n"+
                  "This section of the room has pictures of the 1997 and 1998\n"+
                   "Stanley Cup champions",
"equipment","There is lots of weightlifting equipment.  There are\n"+
                     "machines for working on your chest, arms, legs, etc.\n"+
                     "There are ten machines total",
"rack","This is a metal rack which contains two rows of dumbbells",
});
dest_dir = ({
 "/players/jenny/wings/rooms/fit1","south",
 "/players/jenny/wings/rooms/fit4","west",
});
}
short() {
return BOLD+RED+"Fitness Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
