inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
    set_search(BOLD+"You notice some bubble gum stuck under the counter."+NORM);
     set_listen(BOLD+"You can hear some activity way down on the ice surface."+NORM);
long_desc=
"This is a long narrow booth where sports writers can watch,\n"+      
"and report on, the game.  A counter runs along the booth's\n"+
"window.  This is meant to be used as a work surface.  There\n"+
"are plenty of electrical outlets for the writer's laptops,\n"+
"and lots of chairs to sit on.  The walls are plain white,\n"+
"and the thin red carpet has many stains on it.\n";
items = ({
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"gum","Some inconsiderate writer stuck their gum under the counter",
"window","This window provides a good view of the ice surface.  It has no glass\n"+
                  "so a person could easily 'crawl' through it into the stands",
"counter","This is a long counter which runs along the booth, next to the window.\n"+
               "It is meant to be used as a work surface for the writers.  It has a lot\n"+
               "of scratches and pen marks",
"chairs","These metal chairs have very little padding",
"walls","The walls are white, and a little bit dirty",
"outlets","There are many electrical outlets in this room.  They are often\n"+
                 "used by the writers to plug in their laptops",
});

dest_dir = ({
"/players/jenny/wings/rooms/2h5","west",
});
}
short() {
return BOLD+WHT+"Press Box"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("window","crawl");
}
window(arg) {
if(!arg) {return 0;}
if(arg == "window" | arg == "stands") {
TP->move_player("into the stands#players/jenny/wings/rooms/stands2c7.c");
return 1; }
}
