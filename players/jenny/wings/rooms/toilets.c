inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("kirk maltby"))  {
if(random(10) > 5) {
MOCO("/players/jenny/wings/mobs/players/maltby.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"A recent cleaning leaves the air smelling like disinfectant."+NORM);
     set_listen(BOLD+"You can hear the showers running close by."+NORM);
long_desc=
"The bathroom facilities of the locker room are very clean.  The\n"+      
"walls are made up of large red and white tiles, and the floor consists\n"+
"of smaller white tiles.  There are 8 stalls along the north wall, and\n"+
"5 urinals along the west wall.  On the south wall is a row of 5 sinks,\n"+
"with a small ledge and large mirror above them.  A blow dryer is\n"+
"on each side of the sinks.\n";
items = ({
"walls","The walls are made up of large red and white tiles, which are\n"+
              "alternating to form a checkered pattern",
"sinks","A row of 5 sinks are sunken into a black counter along the south\n"+
           "wall.  Each sink has a handle for hot and cold water, as well as\n"+
            "a liquid soap dispenser",
"handles","Each sink has small glass handles for hot and cold water",
"dispenser","Small metal liquid soap dispensers are built into each sink",
"counter","A black counter along the north wall holds 5 sinks",
"mirror","A large mirror goes from above the sinks, almost up to the ceiling",
"ledge","A small ledge above the sinks.  This is a good spot set things",
"tile","The walls are made of large red and white tile, while the floor is\n"+
           "made up of smaller white tiles",
"floor","The floor is made up of small white tiles",
"stalls","The grey stalls go from about a foot above the floor, to about 2\n"+
              "feet below the ceiling.  There is a toilet in each stall",
"toilet","A plain white porcelain toilet sits in each stall",
"urinals","Five white porcelain urinals are along the west wall.  They are\n"+
               "about 18 inches wide and stretch all the way down to the ground",
"blow dryer","White blow dryers are on each side of the row of sinks.  There\n"+
                       "is a shiny metal button you press to start them",
"button","A large shiny metal button is on each blow dryer",
});
dest_dir = ({
 "/players/jenny/wings/rooms/shower","east",
});
}
short() {
return BOLD+RED+"Red Wings Locker Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("dryers","press");
add_action("dryers","push");
}
dryers(arg) { 
if(!arg) { return 0; }
if(arg == "button" | arg == "the button")  {
write("You press the button and turn on the blow dryer\n"+
           "A steady stream of warm air comes out of it.\n");
say(TPN+" presses the button and turns on the blow dryer\n");
return 1; }}
