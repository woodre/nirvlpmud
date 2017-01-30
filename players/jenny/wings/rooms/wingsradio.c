inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("paul woods"))  {
MOCO("/players/jenny/wings/mobs/other/woods.c"),this_object()); }
if(!present("ken kal"))  {
MOCO("/players/jenny/wings/mobs/other/kal.c"),this_object()); }
    if(arg) return;
    set_light(1);
    set_search(BOLD+"You notice a folder on one of the chairs."+NORM);
     set_listen(BOLD+"You can hear some activity way down on the ice surface."+NORM);
long_desc=
"This is a small booth where local radio broadcasts the game.  It\n"+      
"is used by WJR (760 AM).  The booth has plain white walls, and\n"+
"thin red carpet.  Sitting in front of the window, there is a long\n"+
"table with a monitor, headsets, and microphones on it.  A few\n"+
"chairs are scattered throughout the booth.  There is a thick\n"+
"folder laying on one of the chairs.\n";
items = ({
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"window","This window provides a good view of the ice surface.  It has no glass\n"+
                  "so a person could easily 'crawl' through it into the stands",
"ice surface","The ice surface is set up for hockey.  There are nets at each end of\n"+
                 "the rink, and a few players out there practicing",
"headsets","These are headsets which let the broadcasters have contact with\n"+
                   "their producer",
"microphones","These are small microphones which clip onto the shirt collar.\n"+
                          "They allow the broadcasters to keep their hands free while\n"+
                          "announcing the game",
"table","A long table which the radio announcers use as a work surface.  It has\n"+
             "a monitor, headsets, and microphones on it",
"monitor","A television monitor which allows the broadcasters to see instant replays",
"chairs","These are plain folding metal chairs.  One of them has a thick folder on it",
"folder","A thick folder which contains detailed stats on every player",
});

dest_dir = ({
 "/players/jenny/wings/rooms/2h2","east",
});
}
short() {
return BOLD+WHT+"The "+RED+"WJR "+WHT+"radio booth"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("window","crawl");
}
window(arg) {
if(!arg) {return 0;}
if(arg == "window" | arg == "stands" | arg == "through window" || arg == "through the window") {
TP->move_player("into the stands#players/jenny/wings/rooms/stands2c5.c");
return 1; }
}
