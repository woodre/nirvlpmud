inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("chelios"))  {
if(random(100) < 75) {
MOCO("/players/jenny/wings/mobs/players/chelios.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The smell of sweat hangs in the air."+NORM);
long_desc=
"This is the fitness room inside of Joe Louis Arena.  It is used\n"+      
"by the Red Wing players to help maintain peak physical condition.\n"+
"It is pretty big, and can be used by many players at once.  The\n"+
"thin red carpet is unstained and looks fairly new.  The walls are\n"+
"painted white, with pictures all around the room.  This section\n"+
"of the room has four treadmills and two stairmaster machines.\n";
items = ({
"carpet","This thin red carpet was just put in last year",
"walls","The walls are painted white, and have pictures on them",
"pictures","These are pictures of Detroit's Stanley Cup winning teams.\n"+
                  "This section of the room has pictures of the 1943 and 1950\n"+
                   "Stanley Cup champions",
"treadmills","These are four treadmills which the players use to keep\n"+
                   "in shape.  They can be programmed for time, milage,\n"+
                    "or even to keep your heart rate at a certain level for a\n"+
                   "certain amount of time",
"stairmaster","These are two stairmaster machines which the players use\n"+
                        "to build up their leg muscles.  They can be programed for\n"+
                       "time or a certain number of steps",
"stairmasters","These are two stairmaster machines which the players use\n"+
                        "to build up their leg muscles.  They can be programed for\n"+
                       "time or a certain number of steps",
});

dest_dir = ({
 "/players/jenny/wings/rooms/fit4","north",
 "/players/jenny/wings/rooms/fit1","east",
});
}
short() {
return BOLD+RED+"Fitness Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
