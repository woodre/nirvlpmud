inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("mickey redmond"))  {
MOCO("/players/jenny/wings/mobs/other/redmond.c"),this_object()); }
if(!present("ken daniels"))  {
MOCO("/players/jenny/wings/mobs/other/daniels.c"),this_object()); }
    if(arg) return;
    set_light(1);
    set_search(BOLD+"You notice some cool electronic equipment on the table."+NORM);
     set_listen(BOLD+"You can hear some activity way down on the ice surface."+NORM);
long_desc=
"This is a small booth where local television reports on the game.\n"+      
"It is used by the UPN 50 or Fox Sports Detroit crew, depending\n"+
"on which is scheduled to do that game.  The booth has plain\n"+
"white walls and thin red carpet.  Sitting in front of the window,\n"+
"there is a long table with a monitor, and other electronic\n"+
"equipment on it.  A few chairs are also scattered throughout\n"+
"the booth.\n";
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
                      "and a machine, which Mickey Redmond uses to draw diagrams for\n"+
                      "the viewers",
"chairs","These are plain folding metal chairs",
});

dest_dir = ({
 "/players/jenny/wings/rooms/2h1","east",
});
}
short() {
return BOLD+WHT+"The "+RED+"channel 50 "+WHT+"broadcast booth"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("window","crawl");
}
window(arg) {
if(!arg) {return 0;}
if(arg == "window" | arg == "stands" | arg == "through window") {
TP->move_player("into the stands#players/jenny/wings/rooms/stands2c3.c");
return 1; }
}
