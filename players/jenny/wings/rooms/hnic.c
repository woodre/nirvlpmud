inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("bob cole") && !present("harry neale"))  {
MOCO("/players/jenny/wings/mobs/other/neale.c"),TO); 
MOCO("/players/jenny/wings/mobs/other/cole.c"),TO); }
    if(arg) return;
    set_light(1);
    set_search(BOLD+"You notice some cool electronic equipment on the table."+NORM);
     set_listen(BOLD+"You can hear some activity way down on the ice surface."+NORM);
long_desc=
"This is a small booth where out of town television can report\n"+      
"on the game.  It is currently being used by the CBC Hockey\n"+
"Night in Canada crew.  The booth has plain white walls, and\n"+
"thin red carpet.  Sitting in front of the window, there is a\n"+
"long table with a monitor, and other electronic equipment,\n"+
"on it.  A few chairs are also scattered throughout the booth.\n";
items = ({
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"window","This window provides a good view of the ice surface.  It has no glass\n"+
                  "so a person could easily 'crawl' through it into the stands",
"ice surface","The ice surface is set up for hockey.  There are nets at each end of\n"+
                 "the rink, and a few players out there practicing",
"table","A long table which the television crew uses as a work surface.  It has\n"+
               "electronic equipment and a monitor on top of it",
"monitor","A television monitor which allows the broadcasters to see instant replays",
"equipment","You see headsets, for communicating with the technicians, microphones,\n"+
                      "and a machine for drawing diagrams to be shown on T.V",
"chairs","These are plain folding metal chairs",
});

dest_dir = ({
"/players/jenny/wings/rooms/hnic2","north",
 "/players/jenny/wings/rooms/2h7","west",
});
}
short() {
return BOLD+WHT+"The "+BLU+"CBC"+WHT+" broadcast booth"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("window","crawl");
}
window(arg) {
if(!arg) {return 0;}
if(arg == "window" || arg == "through window" || arg == "through the window" || arg == "stands") {
TP->move_player("into the stands#players/jenny/wings/rooms/stands2c1.c");
return 1; }
}
