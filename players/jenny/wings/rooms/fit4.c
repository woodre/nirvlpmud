inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("larionov"))  {
if(random(100) < 60) {
MOCO("/players/jenny/wings/mobs/players/larionov.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The smell of sweat hangs in the air."+NORM);
long_desc=
"This is the fitness room inside of Joe Louis Arena.  It is used\n"+      
"by the Red Wing players to help maintain peak physical condition.\n"+
"It is pretty big, and can be used by many players at once.  The\n"+
"thin red carpet is unstained and looks fairly new.  The walls are\n"+
"painted white, with pictures all around the room.  There are no\n"+
"machines in this section of the room.  It is left open for\n"+
"miscellaneous exercises.\n";
items = ({
"carpet","This thin red carpet was just put in last year",
"walls","The walls are painted white, and have pictures on them",
"pictures","These are pictures of Detroit's Stanley Cup winning teams.\n"+
                  "This section of the room has pictures of the 1952, 1954, and\n"+
                   "1955 Stanley Cup champions",
});
dest_dir = ({
 "/players/jenny/wings/rooms/fit2","south",
 "/players/jenny/wings/rooms/fit3","east",
});
}
short() {
return BOLD+RED+"Fitness Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
